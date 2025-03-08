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
            if(cache_list[0].empty())
            {
                return -1;
            }
            for (auto it =cache_list[0].begin();it!=cache_list[0].end();++it){
                if (it->second-it->first+1>size)
                {
                    x=1;
                    start=it->first;
                    it->first=it->first+size;
                    break;
                    
                }
                else if(it->second-it->first+1==size)
                {
                    x=2;
                    start=it->first;
                    it = cache_list[0].erase(it);
                    break;
                } 
            }
            if(x==0)
            {
                return -1;
            }
            //加入东西
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
            int size =0;
            if (cache_list.contains(mID))
            {
                for (auto it =cache_list[mID].begin();it!=cache_list[mID].end();++it){
                    size=size+it->second-it->first+1;
                    cache_list[0].push_back(*it);
                }
                cache_list.erase(mID);
                sort(cache_list[0].begin(), cache_list[0].end());
                if(cache_list[0].size()>=2)
                {
                    //cout<<"clean"<<endl;
                    auto cur = cache_list[0].begin();
                    while(cur !=cache_list[0].end() && cur+1!=cache_list[0].end())
                    {
                        if (cur->second +1==(cur+1)->first){
                            cout<<cur->first<<" "<<cur->second<<" "<<(cur+1)->first<<" "<<(cur+1)->second<<endl;
                            (cur+1)->first=cur->first;
                            cur=cache_list[0].erase(cur);
                        }
                        else
                        {
                            ++cur;
                        }
                    }
                }
                //cout<<cache_list[0].size()<<endl;
                
            }
            else{
            }
            return size;
        }
    private:
        map<int,vector<IntPair>> cache_list;
       
    };
    

int main(){
    Allocator* obj = new Allocator(50);
   
    cout<<obj->allocate(12,6)<<endl;
    cout<<obj->allocate(28,16)<<endl;
    cout<<obj->allocate(17,23)<<endl;
    cout<<obj->allocate(50,23)<<endl;
    cout<<obj->freeMemory(6)<<endl; 
    cout<<obj->freeMemory(10)<<endl;
    cout<<obj->freeMemory(10)<<endl;
    cout<<obj->allocate(16,8)<<endl;
    cout<<obj->allocate(16,8)<<endl;
    cout<<obj->allocate(17,41)<<endl;
    cout<<obj->allocate(44,27)<<endl;
    cout<<obj->allocate(12,45)<<endl;
    cout<<obj->freeMemory(33)<<endl;
    cout<<obj->freeMemory(8)<<endl;
    cout<<obj->freeMemory(16)<<endl;
    cout<<obj->freeMemory(23)<<endl;
    cout<<obj->freeMemory(23)<<endl;
    cout<<obj->freeMemory(23)<<endl;
    cout<<obj->freeMemory(29)<<endl;
    cout<<obj->allocate(38,32)<<endl;
    cout<<obj->freeMemory(29)<<endl;
    cout<<obj->freeMemory(6)<<endl;
}