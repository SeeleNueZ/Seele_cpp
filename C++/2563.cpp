#include <bits/stdc++.h>
using namespace std;
    // 首先输出的是个数，其次这个结果本身顺序不影响，因此可以排序。
    // 然后经典小变形：lower−nums[j]≤nums[i]≤upper−nums[j]（0<=i<j）
    // ***** 关键步骤问题等价
    ///计算 ≤upper−nums[j] 的元素个数，减去 <lower−nums[j] 的元素个数，即为满足上式的元素个数。
    // ******因为这样我们就能简易处理了
    // 这里需要使用神奇妙妙工具相向三指针
    // 简单来说这个东西是处理xyz问题的，我们首先固定遍历y，对于每一个y，x放在y右边一个，z放倒数最后一个，
    // 然后看x+y+z的值与标准h的大小，大了x右移，小了z左移，如此遍历
    // 我们这里是在搜存上下界，因此固定的j之后就开始找 >upper−nums[j] 的第一个数，
    // 注意这个r是i的右边，i<j，因此结果需要与j比较，比j大那就是j
    // l是i的左边边界，一样的缩放道理
    class Solution {
        public:
            long long countFairPairs(vector<int>& nums, int lower, int upper) {
                ranges::sort(nums);
                long long ans = 0;
                int l = nums.size(), r = l;
                for (int j = 0; j < nums.size(); j++) {
                    while (r && nums[r - 1] > upper - nums[j]) {
                        r--;
                    }
                    while (l && nums[l - 1] >= lower - nums[j]) {
                        l--;
                    }
                    // 在方法一中，二分的结果必须 <= j，方法二同理
                    ans += min(r, j) - min(l, j);
                }
                return ans;
            }
        };
        int main() {
            int nums[]={0,1,7,4,4,5};
            vector<int> a(nums,nums+4);
            Solution a1 = Solution();
            cout<<a1.countFairPairs(a,3,6);
            return 0;
        }