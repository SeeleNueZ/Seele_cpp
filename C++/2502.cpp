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
            if (cache_list.contains(mID)){
                cout<<"------"<<endl;
                cout<<(cache_list[mID].begin()->first)<<endl;
            }
            
            return 0;
        }
        
        int freeMemory(int mID) {
            return 0;
        }
    private:
        map<int,vector<IntPair>> cache_list;
    };
    

int main(){
    Allocator* obj = new Allocator(100);
    int param_1 = obj->allocate(10,0);
    int param_2 = obj->freeMemory(0);
}