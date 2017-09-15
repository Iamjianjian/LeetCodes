#include <stdio.h>
#include <stdlib.h>
/*
	Problem Description
	度度熊是一只喜欢探险的熊，一次偶然落进了一个m*n矩阵的迷宫，
	该迷宫只能从矩阵左上角第一个方格开始走，只有走到右上角的第
	一个格子才算走出迷宫，每一次只能走一格，且只能向上向下向右向上向下向右向上向下向右向上向下向右向上向下向右向上向下向右向上向下向右向上向下向右
	走以前没有走过的格子，每一个格子中都有一些金币（或正或负，
	有可能遇到强盗拦路抢劫，度度熊身上金币可以为负，需要给强盗
	写欠条），度度熊刚开始时身上金币数为0，问度度熊走出迷宫时候
	身上最多有多少金币？
*/

/*
	solution description
	我们考虑这样一个子结构
	第i列的每个点(i,j)的最大金币数
	(i,j)有上下左三个选择
	由于不能想左走，不能回头
	如果（i，j）是从上下来
	则（i，j-1）也是从上或从左来
	那我们可以先求(i，0)，接着就从上面下来的各个值
	从下面同理
	（不要忘了中间的点从左来）
*/
int main()
{
	//这里随意定义了nm
    const int n=3;
    const int m=4;
    int matrix[3][4]={{1 ,-1, 1, 0},{2, -2 ,4 ,2},{3, 5 ,1 ,-90}};
	//dp1 记录最大值
    int dp1[n];
    int i;
    int temp=0;
	//第一行只能从上面下来
    for (i=0;i<3;i++)
    {

        temp+=matrix[i][0];
        dp1[i]=temp;
    }
	//测试
    for (i=0;i<3;i++)
    {
        printf("%d ",dp1[i]);

    }
    printf("\n");
    int time;
    int dp2[n];
    int dp3[n];
    for (time=1;time<m-1;time++)
    {

        for (i=0;i<n;i++)
        {
            dp2[i]=dp1[i]+matrix[i][time];//dp2 从左边过来
            dp3[i]=dp2[i];
        }
        for (i=1;i<n;i++)
        {
			//从上而下
            if ((dp2[i-1]+matrix[i][time])>dp2[i])
            {
                dp2[i]=dp2[i-1]+matrix[i][time];
            }

        }
        for (i=n-2;0<=i;i--)
        {
			// 从下而上
            if (dp3[i]<(dp3[i+1]+matrix[i][time]))
            {
                dp3[i]=dp3[i+1]+matrix[i][time];
            }
        } 
		//最大值更新
        for (i=0;i<n;i++)
        {
            dp2[i]=(dp2[i]<dp3[i])?dp3[i]:dp2[i];
            dp1[i]=dp2[i];
        }
        for (i=0;i<3;i++)
        {
            printf("%d ",dp1[i]);

        }
        printf("\n");

    }
	//最后一列不需要从下而上
    for (i=0;i<n;i++)
    {
        dp2[i]=dp1[i]+matrix[i][m-1];

    }
    for (i=n-2;0<=i;i--)
    {
        if (dp2[i]<dp2[i+1]+matrix[i][m-1])
        {
            dp2[i]=dp2[i+1]+matrix[i][m-1];
        }
    }
    printf("%d",dp2[0]);
}
