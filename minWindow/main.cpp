#include <iostream>
#include <string>
#include <map>
using namespace std;

/*
    维护两个指针表示窗口
    end右移当当前的字符满足时移动左边使其直到不满足
    https://leetcode.com/problems/minimum-window-substring
*/

class Solution {
public:
    string minWindow(string s, string t)
    {
        if (s==""||t=="")
        {
            return "";
        }
        map<char ,int >sc;//目前窗口内任然需要的各个字母个数
        for (int i=0;i<26;i++)
        {
            sc.insert(pair<char,int>('a'+i,0));
            sc.insert(pair<char,int>('A'+i,0));
        }
        for (int i=0;i<t.size();i++)
        {
            sc[t[i]]+=1;
        }
        map<char,bool>tc;//字母是否在t中出现
        for (int i=0;i<26;i++)
        {
            tc['a'+i]=false;
            tc['A'+i]=false;
        }
        for (int i=0;i<t.size();i++)
        {
            tc[t[i]]=true;
        }
        int coun=t.size();//目前窗口还欠缺的字母
        int begin=0;
        int end=begin;
        int minbe=-1;
        int minend=-1;
        for (;end<s.size();end++)
        {
            if (tc[s[end]]==true)
            {
                sc[s[end]]=sc[s[end]]-1;
                if (0<=sc[s[end]])
                {
                    coun--;
                    if (coun==0)
                    {
                        if (minbe==-1)
                        {
                            minend=end;
                            minbe=begin;
                        }
                        else if  ((end-begin)<=(minend-minbe))
                        {
                            minend=end;
                            minbe=begin;
                        }
                        for (;begin<end;begin++)
                        {
                            if (tc[s[begin]]==true)
                            {
                                sc[s[begin]]=sc[s[begin]]+1;
                                if (0<sc[s[begin]])
                                {
                                    coun++;
                                    begin++;
                                    break;
                                }
                                else if ((end-begin-1)<=(minend-minbe))
                                {
                                    minend=end;
                                    minbe=begin+1;
                                }
                            }
                            else if ((end-begin-1)<=(minend-minbe))
                            {
                                minend=end;
                                minbe=begin+1;
                            }
                        }
                    }
                }
            }
        }
        if (minbe==-1)
        {
            return "";
        }
        char result[minend-minbe+2];
        result[minend-minbe+1]='\0';
        for (int i=0;minbe<=minend;minbe++,i++)
        {
            result[i]=s[minbe];
        }
        return result;
    }
};

int main()
{
    Solution a;
    cout <<a.minWindow("ab","b");
    return 0;
}
