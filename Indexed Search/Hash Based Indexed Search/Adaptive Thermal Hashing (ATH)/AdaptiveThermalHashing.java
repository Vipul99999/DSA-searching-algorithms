import java.util.*;

class ATH {

    List<Map<Integer,Integer>> buckets;

    ATH(){

        buckets=new ArrayList<>();

        for(int i=0;i<8;i++)
            buckets.add(new HashMap<>());
    }

    int hash(int k){

        return Math.abs(k)%buckets.size();
    }

    void insert(int k,int v){

        buckets.get(hash(k)).put(k,v);
    }

    Integer search(int k){

        return buckets.get(hash(k)).get(k);
    }

    public static void main(String[] args){

        ATH h=new ATH();

        h.insert(11,110);

        System.out.println(h.search(11));
    }
}
