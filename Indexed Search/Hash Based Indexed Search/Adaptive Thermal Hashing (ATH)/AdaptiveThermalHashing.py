class ATH:

    def __init__(self,size=8):
        self.table=[[] for _ in range(size)]
        self.temp=[0]*size

    def h(self,key):
        return key%len(self.table)

    def insert(self,key,val):

        i=self.h(key)

        self.table[i].append((key,val))

        if len(self.table[i])>3:
            self.rehash()

    def rehash(self):

        old=self.table

        self.table=[[] for _ in range(len(old)*2)]

        for bucket in old:
            for k,v in bucket:
                self.table[self.h(k)].append((k,v))

    def search(self,key):

        i=self.h(key)

        self.temp[i]+=1

        for k,v in self.table[i]:
            if k==key:
                return v

        return None


h=ATH()

h.insert(10,100)

print(h.search(10))
