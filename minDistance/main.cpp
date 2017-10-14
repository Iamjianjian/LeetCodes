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
            D[][] ��ʾ�ӵ��ʵ���̾���
            (1 ����D[i][j]���word1[i]==word2[j],��֤��ʱD[i][j]=D[i-1][j-1]��D[i-1][j]+1
                ֤����
                    word[0:i+1]���Ա�ʾΪ���ֱ�����������ĸ�м������ĸ��I1 w1 I2 w2 ......In wi Ii+1
                    word1[i]==word2[j]��ô,��word1[i]�������Եõ� ��D[i-1][j-1]�ľ���
                    ����ʱ,��word1[i]Ϊword2[j-k]ʱ,k>0,��ô��ʱ���Եõ� ����D[i-1][j-k-1]+k-1(word1[i]==word2[j-k]) ��D[i-1][j-k-1]+k(word1[i]!=word2[j-k])
                    D[i-1][j-1]<=D[i-1][j-k-1]+k (��ΪD[i-1][j-1]����һ������Ϊ��word1[i-1]��word2[j-k-1]+insert k �� )
                    ������ʱ(delete word1[i]),D[i-1][j-k](0<k<j)+insert k,�ٿ���D[i-1][j]+1
             (2 word1[i]!=word2[j]ʱ
                    ͬ�� word[0:i+1]���Ա�ʾΪ���ֱ�����������ĸ�м������ĸ��I1 w1 I2 w2 ......In wi Ii+1
                    (( 1 word1[i] replace word2[j]
                    (( 2 word1[i] ��replace word2[j],��ô����D[i][j-k]+insert k, ����ά��һ��minֵ������ÿ�α���D[i][j-k](0<k<j+1)
                    ����ȡСֵ
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
            //��ʼ��mindis,��D[i][0]
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
                mindis++;//ÿ��insert��1 ����Ҫ����mindis mindis��ʾword1[i]�����򲻱���ʱD[i-1][j-k]+insert k ��distance,��ʱ��mindisΪ
                mindis=(mindis<Distance[i-1][j]+1)?mindis:Distance[i-1][j]+1;//����word1[:i]��word2[:j+1]+1
                if (word1[i]==word2[j])
                {
                    //��word1[i]==word[2]ʱ���ܸ���mindis
                    mindis=(mindis<Distance[i-1][j-1])?mindis:Distance[i-1][j-1];
                    Distance[i][j]=mindis;
                    mindis=(mindis<Distance[i][j])?mindis:Distance[i][j];
                }
                else
                {
                    //����ͬ����word1[i]replacae word2[j]
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
