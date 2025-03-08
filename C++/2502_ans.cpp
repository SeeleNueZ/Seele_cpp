#include <bits/stdc++.h>
using namespace std;
using IntPair = pair<int,int>;

class Allocator {
    public:
        Allocator(int n): n(n), memory(n) {}
        
        int allocate(int size, int mID) {
            int count = 0;
            for (int i = 0; i < n; ++i) {
                if (memory[i]) {
                    count = 0;
                }
                else {
                    ++count;
                    if (count == size) {
                        for (int j = i - count + 1; j <= i; ++j) {
                            memory[j] = mID;
                        }
                        return i - count + 1;
                    }
                }
            }
            return -1;
        }
        
        int freeMemory(int mID) {
            int count = 0;
            for (int i = 0; i < n; ++i) {
                if (memory[i] == mID) {
                    ++count;
                    memory[i] = 0;
                }
            }
            return count;
        }
    
    private:
        int n;
        vector<int> memory;
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