class Solution {
    // 简单来说先说明几个思路问题，一个数组里面可以实现要求的数组对数量与每一个数字相等的数量有关
    // 3个1 2个2 3个3 组成的字符串无论怎么排列都是有3+1+3个满足要求的东西
    //所以又可以哈希表点出现次数，来确定一个串里面到底有几个，同时设计可以同时扫数组同时出答案，实际上每次碰到i等于每次加上等于hash[i]的值，
    // 解释一下就是扫到了第4个1，前面三个1都多了一个，所以+3（对这个hash里面是个数，使用先加厚更新个数的方案正好能完美解决）
    // 双指针：解决的问题是有几组这样的数组
    long long pow1(long long x, long long n) {
        long long res = 1;
        while (n) {
            if (n & 1) {
                res = res * x % MOD;
            }
            x = x * x % MOD;
            n >>= 1;
        }
        return res;
    }
    public:
        int countGoodNumbers(long long n) {
            long long x = (n+1)/2;
            long long y = n/2;
            int ans = pow1(4,y)*pow1(5,x)% MOD;
            return ans;
            
        }
    };