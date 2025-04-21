#include <bits/stdc++.h>
using namespace std;
    // 题目简单描述是提供了一个数组的相邻数的差的数组。然后给出上界下界找出有几种可能性
    // 其实差给出后这个数组的数连接形成的形状已经固定了，最多只能在上下界里面上下移动一下
    // 这里我们就要使用非常专业的词汇：前缀和最大和前缀和最小的值
    // 什么是前缀和呢，就是一个数组前n个数组之和。
    // 这样前缀和最大和最小其实就是所谓的确定了数组的整体范围。跟上下界比较一下就能出结果。
    class Solution 
    {
        public:
            int numberOfArrays(vector<int>& differences, int lower, int upper) {
                long long temp = 0 ; // 这个就是在扮演前缀和数组，但是这里可以偷懒直接拿一个temp算出来
                long long max_n = 0;
                long long min_n = 0;
                // 可以令manx，min=0，因为初始的temp其实是我们指定的，它是前缀和第一个，也是原始数组第一个。max比较是原始数组，自然可以是第一个。
                // 另外difference仅有一个-40这种情况，初始值没有设置为默认的temp会有逻辑bug
                for(auto i : differences)
                {
                    temp =temp+i;
                    max_n = max(temp,max_n);
                    min_n = min(temp,min_n);

                }
                return max(upper - lower - max_n + min_n + 1, 0LL);
                
            }
        };
        int main() {
            int nums[]={-40};
            vector<int> a(nums,nums+1);
            Solution a1 = Solution();
            cout<<a1.numberOfArrays(a,-46,53);
            return 0;
        }