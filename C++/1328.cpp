#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        string breakPalindrome(string palindrome) {
            if(palindrome.length()==1)
            {
                return "";
            }
            int len=palindrome.length()/2;
            int up=10000;
            int down=10000;
            for(int i=0;i<len;i++)
            {
                if (palindrome[i]!='a')
                {
                    if(i<down)
                    {
                        down= i;
                    }
                }
                else
                {
                    if(i<up)
                    {
                        up=i;
                    }
                }
            }
            if(down!=10000)
            {
                palindrome[down]='a';
            }
            else
            {
                palindrome[palindrome.length()-up-1]=palindrome[palindrome.length()-up-1]+'1'-'0';
            }
            return palindrome;


            //up修改后面的，所以应该算到映射的位置。
            //down是修改前面的
        }
    };
    int main()
    {
        Solution* sol = new Solution();
        string str=sol->breakPalindrome("aa");
        cout<<str;
    }
    