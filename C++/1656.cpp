#include <bits/stdc++.h>
using namespace std;
class OrderedStream {
    private:
    vector<string> list;
    int ptr;
    public:
        OrderedStream(int n) {
            list.resize(n+2);
            ptr = 1;
        }
        
        vector<string> insert(int idKey, string value) {
            list[idKey]=value;
            vector<string> res;
            while(!list[ptr].empty()){
                res.push_back(list[ptr]);
                ptr++;
            }

            return res;
        }
    };
    int main(){
        int n=5;
        int a[5] = {3,1,2,5,4};
        string b[5]={"ccccc", "aaaaa", "bbbbb", "eeeee" ,"ddddd"};
        OrderedStream* obj = new OrderedStream(n);
        vector<string> res;
        res=obj->insert(a[0],b[0]);
        res=obj->insert(a[1],b[1]);
        res=obj->insert(a[2],b[2]);
        for (size_t i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        
    }