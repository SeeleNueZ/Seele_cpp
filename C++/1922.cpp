class Solution {
    // 会越界，所以得乘一个除一个
    // 需要使用快速幂函？
    // 抄的快速幂次方 原理是使用 x x^2 x^4 中的若干个来算出x^m ,m可以分解乘二进制来算，然后对应位数就是需要乘上去的值
    const int MOD = 1000000007;
    // long long pow1(long long x,long long y)
    // {
    //     long long res = 1;
    //     while (y>=1)
    //     {
    //         res = res * x % MOD;
    //         y =y-1;
    //     }
        
    //     return res;
        
    // }
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