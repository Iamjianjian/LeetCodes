#include <iostream>
#include <string>
using namespace std;
//https://leetcode.com/problems/edit-distance
class Solution {
public:
    int minDistance(string word1, string word2) {
        int l1=word1.size();
        int l2=word2.size();
        int Distance[l1][l2];
        /*
            D[][] 表示子单词的最短距离
            (1 对于D[i][j]如果word1[i]==word2[j],可证此时D[i][j]=D[i-1][j-1]或D[i-1][j]+1
                证明：
                    word[0:i+1]可以表示为部分保留下来的字母中间插入字母既I1 w1 I2 w2 ......In wi Ii+1
                    word1[i]==word2[j]那么,把word1[i]保留可以得到 即D[i-1][j-1]的距离
                    保留时,当word1[i]为word2[j-k]时,k>0,那么此时可以得到 距离D[i-1][j-k-1]+k-1(word1[i]==word2[j-k]) 或D[i-1][j-k-1]+k(word1[i]!=word2[j-k])
                    D[i-1][j-1]<=D[i-1][j-k-1]+k (因为D[i-1][j-1]其中一个可能为由word1[i-1]到word2[j-k-1]+insert k 个 )
                    不保留时(delete word1[i]),D[i-1][j-k](0<k<j)+insert k,再考虑D[i-1][j]+1
             (2 word1[i]!=word2[j]时
                    同理 word[0:i+1]可以表示为部分保留下来的字母中间插入字母既I1 w1 I2 w2 ......In wi Ii+1
                    (( 1 word1[i] replace word2[j]
                    (( 2 word1[i] 不replace word2[j],那么就是D[i][j-k]+insert k, 我们维护一个min值而不用每次遍历D[i][j-k](0<k<j+1)
                    二者取小值
        */
        bool flag=false;
        for (int i=0;i<l2;i++)
        {
            if (word1[0]==word2[i])
            {
                flag=true;
            }
            if (flag)
            {
                Distance[0][i]=i;
            }
            else
            {
                Distance[0][i]=i+1;
            }
        }
        int temp;
        int mindis;
        for (int i=1;i<l1;i++)
        {
            //初始化mindis,即D[i][0]
            if (word1[i]==word2[0])
            {
                mindis=i;
            }
            else
            {
                mindis=(i+1<(Distance[i-1][0]+1))?(i+1):Distance[i-1][0]+1;
            }
            Distance[i][0]=mindis;
            for (int j=1;j<l2;j++)
            {
                mindis++;//每次insert加1 所以要更新mindis mindis表示word1[i]保留或不保留时D[i-1][j-k]+insert k 的distance,此时的mindis为
                mindis=(mindis<Distance[i-1][j]+1)?mindis:Distance[i-1][j]+1;//考虑word1[:i]到word2[:j+1]+1
                if (word1[i]==word2[j])
                {
                    //在word1[i]==word[2]时可能更新mindis
                    mindis=(mindis<Distance[i-1][j-1])?mindis:Distance[i-1][j-1];
                    Distance[i][j]=mindis;
                    mindis=(mindis<Distance[i][j])?mindis:Distance[i][j];
                }
                else
                {
                    //不相同考虑word1[i]replacae word2[j]
                    mindis=(mindis<Distance[i-1][j-1]+1)?mindis:Distance[i-1][j-1]+1;
                    Distance[i][j]=mindis;
                }
            }
        }
        return Distance[l1-1][l2-1];
    }
};

int main()
{
    Solution s;
    string a("1112113");
    string b("234");
    cout <<
    s.minDistance(a,b);
    return 0;
}
