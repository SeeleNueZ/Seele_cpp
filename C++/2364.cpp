#include <bits/stdc++.h>
using namespace std;
    // 考虑题目 i < j 且 j - i != nums[j] - nums[i]，先变形构造 nums[i]- i != nums[j] -j
    // 然后还是很难，考虑反方向，总共对数是n(n-1)/2，我们可以点nums[i]- i = nums[j] -j的个数X。
    // 然后一个很帅的减法解决问题。然后总所周知应该用hash表统计nums[i]有几个，键用nums[i]-i，值用个数。
    class Solution {
        public:
            long long countBadPairs(vector<int>& nums) {
                long long n =nums.size();
                long long ans = n*(n-1)/2;
                unordered_map<int,int>cnt;
                for (int i =0;i<n;i++)
                {
                    ans = ans - cnt[nums[i]-i];
                    cnt[nums[i]-i]++;
                    
                }
                return ans;

            }
        };

        int main() {
            int nums[]={4,1,3,3};
            vector<int> a(nums,nums+4);
            Solution a1 = Solution();
            cout<<a1.countBadPairs(a);
            return 0;
        }