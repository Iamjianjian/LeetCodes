#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

char*** groupAnagrams(char** strs, int strsSize, int** columnSizes, int* returnSize) {
    int i,k,j;
    int nums[strsSize][26];//出现过的不同的字符串组合的各个子母出现的次数
    int count=0;
    char *temp;
    int find;
    int tn[26];
    memset(tn,0,26);
    char **results[strsSize];
    memset(nums[0],0,26);
    for (i=0;i<strsSize;i++)
    {
        temp=strs[i];
        find=1;
        for (k=0;k<count;k++)
        {

            for(j=0;temp[j]!='\0';j++)
            {
                tn[temp[j]-'a']+=1;
            }
            for (j=0;j<26;j++)
            {

                if (tn[j]!=nums[k][j])
                {
                    find=0;
                    break;
                }
            }
            if (find)
            {
                results[k]
            }
        }
    }
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
