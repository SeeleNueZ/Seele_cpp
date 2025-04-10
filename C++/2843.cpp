#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int countSymmetricIntegers(int low, int high) {
            int n =0;
            for(int i =low;i<=high;i++)
            {
                if(i <=99 && (i/10 == i%10))
                {
                    n++;
                }
                else if(i <=10000 && i>1000)
                {
                    int a = i/1000+(i/100)%10;
                    int b = (i%100)/10+i%10;
                    if(a==b)
                    {
                        n++;
                    }
                }
            }
            return n;
        }
    };
    int main()
    {
        Solution* sol = new Solution();
        int str=sol->countSymmetricIntegers(1200,1230);
        cout<<str;
    }