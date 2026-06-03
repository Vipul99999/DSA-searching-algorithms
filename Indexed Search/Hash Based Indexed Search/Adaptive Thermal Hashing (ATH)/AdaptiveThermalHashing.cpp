#include <iostream>
#include <vector>
#include <list>

using namespace std;

class ATH {

    vector<list<pair<int,int>>> table;
    vector<int> temp;

public:

    ATH(int n=8){
        table.resize(n);
        temp.resize(n,0);
    }

    int hashKey(int x){
        return abs(x)%table.size();
    }

    void insert(int k,int v){

        int i=hashKey(k);

        table[i].push_back({k,v});

        if(table[i].size()>3)
            rehash();
    }

    void rehash(){

        auto old=table;

        table.clear();

        table.resize(old.size()*2);

        temp.resize(old.size()*2);

        for(auto& b:old)
            for(auto& p:b)
                table[hashKey(p.first)].push_back(p);
    }

    int search(int k){

        int i=hashKey(k);

        temp[i]++;

        for(auto& p:table[i])
            if(p.first==k)
                return p.second;

        return -1;
    }
};

int main(){

    ATH h;

    h.insert(5,50);

    cout<<h.search(5);

}
