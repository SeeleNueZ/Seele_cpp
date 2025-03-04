#include <bits/stdc++.h>
using namespace std;
using IntPair = pair<int,int>;

class Allocator {
    public:
        Allocator(int n) {
            map<int,vector<IntPair>> cache;
            vector<IntPair> a;
        }
        
        int allocate(int size, int mID) {
            
        }
        
        int freeMemory(int mID) {
            
        }
    };
    

int main(){
    map<int, vector<IntPair>> list;
    vector<IntPair> a;
    a.push_back(make_pair(0,10));
    list.insert(make_pair(0,a));
    auto it = list.find(1);
    if (it != list.end()) {
        for (const auto& pair : it->second) {
            cout << "(" << pair.first << ", " << pair.second << ") ";
        }
        cout << endl;
    } else {
        cout << "键不存在" << endl;
    }
}