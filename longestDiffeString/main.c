#include <stdio.h>
#include <string.h>
//维护两个指针指针之间的字符无重复
int func(char *s)
{
    int l=strlen(s);
    int i,j;
    int ma=0;
    int ischar[26];
    memset(ischar,0,sizeof(ischar));
    for(i=0,j=0;i<l;)
    {
        if(ischar[s[i]-'a']==0)
        {
            ischar[s[i]-'a']=1;
            i++;
        }
        else
        {
            ma=(ma<(i-j))?(i-j):ma;
            memeset(ischar,0,sizeof(ischar));
            j=i;
            ischar[s[i]-'a']=1;
        }
    }
    ma=(ma<(i-j))?(i-j):ma;
    return ma;
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
