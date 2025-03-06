#include <bits/stdc++.h>
using namespace std;
using IntPair = pair<int,int>;

class Allocator {
    public:
        Allocator(int n) {
            vector<IntPair> a;
            a.push_back(make_pair(0,n-1));
            cache_list.insert(make_pair(0,a));
        }
        
        int allocate(int size, int mID) {
            int x =0 ;
            int start=0;
            for (auto it =cache_list[0].begin();it!=cache_list[0].end();++it){
                if (it->second-it->first+1>size)
                {
                    x=1;
                    it->second=it->second-size;
                    start=it->first;

                }
                else if(it->second-it->first+1==size)
                {
                    x=2;
                    cache_list[0].erase(it);
                    start=it->first;
                } 
            }
            if(x==0){
                return -1;
            }


            if (cache_list.contains(mID)){
                cache_list[mID].push_back(make_pair(start,start+size-1));
            }
            else{
                vector<IntPair> a;
                a.push_back(make_pair(start,start+size-1));
                cache_list.insert(make_pair(mID,a));
            }
            
            return start;
        }
        
        int freeMemory(int mID) {
            return 0;
        }
    private:
        map<int,vector<IntPair>> cache_list;
    };
    

int main(){
    Allocator* obj = new Allocator(100);
    cout<<obj->allocate(10,1)<<endl;
    int param_2 = obj->freeMemory(0);
}