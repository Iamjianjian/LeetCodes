#include <iostream>
#include <string >
#include <vector>

using namespace std;

/*
    �ַ��������ķָ��� aba b bbabb a b aba
    ���ٷּ���

    ��̬�滮 Ҫô�����¼ӵ��ַ� Ҫô������
*/

void canpri(string& s,int i,vector<int>& le)
{
    for (int j=i-1;0<=j;j--)
    {
        if (s[j]==s[i])
        {
            bool flag=true;
            for (int k=1;k<=(i-j)/2;k++)
            {
                if (s[i-k]!=s[j+k])
                {
                    false;
                    break;
                }
            }
            if (flag)
            {
                le.push_back(j);
            }
        }
    }
}

int solve (string s)
{

    int result[s.size()];

    for (int i=0;i<s.size();i++)
    {

    }
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
