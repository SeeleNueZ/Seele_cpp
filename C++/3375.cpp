#include <bits/stdc++.h>
using namespace std;

// 更优质的思路：直接在扫的时候统一，发现比K小的直接变-1，发现比K大的次数+1
class Solution {
    public:
        int minOperations(vector<int>& nums, int k) 
        {
            map<int,int> cnt;
            int min = 999;
            for (auto it =nums.begin();it!=nums.end();++it)
            {
                auto it1 = cnt.find(*it);
                if (it1 !=cnt.end())
                {
                    cnt[*it] = cnt[*it]++;
                }
                else
                {
                    cnt[*it]=1;
                }
                if(*it<min)
                {
                    // cout<<"---"<<*it<<endl;
                    min = *it;
                }
            }
            // cout<<min<<endl;
            if (k > min)
            {
                return -1;
            }
            else
            {
                int n = 0;
                int size = cnt.size();
                if (k ==min)
                {
                    n  =size -1;
                }
                else
                {
                    n= size;
                }
                return n;
             }
        }

    };
    int main()
    {
        int nums[]={4,5,6,7,8};
        vector<int> a(nums,nums+5);
        Solution* sol = new Solution();
        int str=sol->minOperations(a,4);
        cout<<str;
    }