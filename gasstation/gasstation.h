#ifndef GASSTATION_H_
#define GASSTATION_H_

/* 
	一个圈里面有加油站，每个加油站的油不是无限，加油站到先一个加油站有耗油量
	求从那个站出发可以完整转一圈
	
	1 只要总油量大于耗油量就可以走完
*/

int gasstation(int *gas,int *cost,int quantity)
{
    int sum=0;//剩余油量
    int total=0;//总油量减去耗油量
    int j=0;//起点
    for (int i=0;i<quantity;i++)
    {
        sum+=gas[i]-cost[i];
        total+=gas[i]-cost[i];
        if (sum<0)//说明从j开始无法转一圈 ,且走过的该路耗油量大于总油量 如果总油量大于耗油量 则另一边没有走的圈必定有解 
        {
            j=i+1;
            sum=0;
        }

    }
    return (0<total)?j:-1;
}
#endif // GASSTATION_H_
