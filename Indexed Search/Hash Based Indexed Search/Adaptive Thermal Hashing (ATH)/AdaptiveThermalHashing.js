class ATH {

    constructor(size=8){

        this.table=Array(size)
            .fill()
            .map(()=>[]);

        this.temp=Array(size).fill(0);
    }

    hash(k){

        return Math.abs(k)%this.table.length;
    }

    insert(k,v){

        let i=this.hash(k);

        this.table[i].push([k,v]);

        if(this.table[i].length>3)
            this.rehash();
    }

    rehash(){

        let old=this.table;

        this.table=Array(
            old.length*2
        ).fill().map(()=>[]);

        old.flat()
           .forEach(
               ([k,v]) =>
               this.table[
                   this.hash(k)
               ].push([k,v])
           );
    }

    search(k){

        let i=this.hash(k);

        this.temp[i]++;

        for(let p of this.table[i])
            if(p[0]===k)
                return p[1];

        return null;
    }
}

const h=new ATH();

h.insert(7,70);

console.log(h.search(7));
