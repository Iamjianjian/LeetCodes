#include <stdio.h>
#include <stdlib.h>

//https://leetcode.com/problems/jump-game-ii/description/
//动态规划贪心
/*
    有贪心性质总是选择当前可以到达的点中distance最大的，也就是下一个点可以到达最远的点
*/
int jump(int* nums, int numsSize) {
    if (numsSize==1)
    {
        return 0;
    }
    int i,j;
    int distance[numsSize];
    for (i=0;i<numsSize;i++)
    {

        distance[i]=i+nums[i];
    }
    int result=1;
    int now=distance[0];
    int last=1;
    int max;
    while (now<numsSize-1)
    {
        result++;
        max=0;
        for(j=last;j<=now;j++)
        {
            if (max<distance[j])
            {
                max=distance[j];
            }
        }
        now=max;

    }
    return result;
}

int main()
{
    int a[]={1,2,3};
    jump(a,3);
    return 0;
}
