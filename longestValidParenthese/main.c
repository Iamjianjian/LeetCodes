#include <stdio.h>
#include <string.h>

int longestValidParentheses(char* s)
{
    int l=strlen(s);
    if(l==0)
    {
        return 0;
    }
    int i=0;
    int ma=0;
    int pointer=-1;
    int poins[l];
    int temp;
    int begin=-1;
    for(i=0;i<l;i++)
    {
        if(s[i]=='(')
        {
            poins[i]=pointer;
            pointer=i;
        }
        else
        {
            if(pointer==-1)
            {
                begin=i;
            }
            else
            {
                pointer=poins[pointer];
                if(pointer==-1)
                {
                    temp=i-begin;
                }
                else
                {
                    temp=i-pointer;
                }
                if(ma<temp)
                {
                    ma=temp;
                }

            }
        }
    }
    return ma;
}
//    int l=strlen(s);
//    int acti=0;
//    int i;
//    int acl[l];
//    int add;
//    int begin,high,ma,low,temp;
//    for(i=0;i<l;i++)
//    {
//        if(s[i]=='(')
//        {
//            acti+=1;
//            acl[i]=acti;
//        }
//        else
//        {
//            acti-=1;
//            if(acti<0)
//            {
//                acl[i]=-1;
//                ac=0;
//            }
//        }
//    }
//    add=0;
//    begin=0;
//    high=0;
//    ma=0;
//    low=0;
//    for(i=0;i<l;i++)
//    {
//        if(acl[i]==-1)//too many ')'
//        {
//            high=i+1;
//            add=0;
//            begin=i+1;
//        }
//        else if(acl[i]==0)
//        {
//            add+=i-begin+1;
//            low=i;
//        }
//        else
//        {
//            if(acl[high]<acl[i])
//            {
//                temp=high;
//                while(acl[temp]!=acl[low])
//                {
//                    temp--;
//                }
//                temp=low-temp+1+add;
//                if(ma<temp)
//                {
//                    ma=temp;
//                }
//                for(;i<l;i++)//find highest
//                {
//                    if(high<acl[i])
//                    {
//                        high=acl[i];
//                    }
//                    else
//                    {
//                        break;
//                    }
//
//                }
//
//            }
//            else
//            {
//                if(acl[i]<=acl[low])
//                {
//                    low=i;
//                }
//            }
//        }
//    }
int main()
{
    char a[]=")()())()()(";
    printf("%d\n",longestValidParentheses(a));
    return 0;
}
