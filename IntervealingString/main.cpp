#include <iostream>
#include <string>
using namespace std;

/*
    https://leetcode.com/problems/interleaving-string/description/

    动态规划  interMark表示是否可以插入成s3

*/

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size()+s2.size()!=s3.size())
        {
            return false;
        }
        if (s3.size()==0)
        {
            return true;
        }
        if (s1.size()==0)
        {
            return s3==s2;
        }
        if (s2.size()==0)
        {
            return s3==s1;
        }
        bool interMark[(s1.size()+1)][(s2.size()+1)];
        interMark[0][0]=true;
        for (int i=1;i<s2.size()+1;i++)
        {
            if (interMark[0][i-1])
            {
                interMark[0][i]=(s3[i-1]==s2[i-1])?true:false;
            }
            else
            {

                interMark[0][i]=false;
            }
        }
        for (int i=1;i<s1.size()+1;i++)
        {
            if (interMark[i-1][0])
            {
                interMark[i][0]=(s3[i-1]==s1[i-1])?true:false;
            }
            else
            {

                interMark[i][0]=false;
            }
        }
        for (int i=1;i<s1.size()+1;i++)
        {
            for (int j=1;j<s2.size()+1;j++)
            {
                if (s1[i-1]==s3[j+i-1]&&interMark[i-1][j])
                {
                    interMark[i][j]=true;
                    continue;
                }
                if (s2[j-1]==s3[j+i-1]&&interMark[i][j-1])
                {
                    interMark[i][j]=true;
                    continue;
                }
                interMark[i][j]=false;
            }
        }
        return interMark[s1.size()][s2.size()];

    }
};

int main()
{
    Solution a;
    string s1="aabcc";
    string s2="dbbca";
    string s3="aadbbcbcac";
    string s4="aadbbbaccc";
    string s5="aa";
    string s6="ab";
    string s7="abaa";
    cout<<a.isInterleave(s5,s6,s7);
    return 0;
}
