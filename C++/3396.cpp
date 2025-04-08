#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int minimumOperations(vector<int>& nums) 
        {
            int A[103]={0};
            int n = 0;
            int cnt = 0;
            for (auto it = nums.rbegin();it !=nums.rend(); it++)
            {
                if (A[*it]==0 && cnt == 0){
                    A[*it]=1;
                }
                else
                {
                    cnt++;
                }
            }
            if (cnt >0)
            {
                n = (cnt+2)/3;
            }
            return n;
        }
    };
    int main()
    {
        int nums[]={4,5,6,7,8};
        vector<int> a(nums,nums+5);
        Solution a1 = Solution();
        cout<<a1.minimumOperations(a);
        return 0;
    }