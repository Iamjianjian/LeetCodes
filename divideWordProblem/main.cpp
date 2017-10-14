#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
    �����ֶμ��� {hello,world}
    �����ֶ��� "hellohelloworld"
    �Ƿ���԰��ֶηֳ��ֶμ����еĵ���
*/

bool ifSub(string& s1,string& s2,int index)
{
    for (int i=0;i<s1.size();i++)
    {
        if (s1[i]!=s2[i+index])
        {
            return false;
        }
    }
    return true;
}

bool canDivedi(vector<string> words,string str)
{
    bool isfind[str.size()+1];
    isfind[0]=true;
    for (int i=1;i<str.size()+1;i++)
    {
        isfind[i]=false;
        for (int j=0;j<words.size();j++)
        {
            if (words[j].size()<=i)
            {
                bool temp=ifSub(words[j],str,str.size()-i);
                if (temp==true&&isfind[i-words[j].size()]==true)
                {
                    isfind[i]=true;
                    break;
                }
            }
        }
    }
    return isfind[str.size()];
}

int main()
{
    vector <string> s;
    string a="hello";
    s.push_back(a);
    a="world";
    s.push_back(a);
    a="oool";
    s.push_back(a);
    a="hellohelloooolworld";
    cout <<canDivedi(s,a);
    return 0;
}
