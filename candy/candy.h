#ifndef CANDY_H_
#define CANDY_H_
#include <iostream>
using namespace std;


/*	
	小朋友分糖，每个小朋友有权值，权值大的要比傍边的多，没人至少一个，最少用多少糖


	找极小值的点只给一个糖旁边的依次增大
*/
int candy(int *rating,int quantity)
{
    int candys[quantity];
    for (int i=0;i<quantity;i++)
    {
        candys[i]=1;
    }
    int lefttop=0;//左边极大值
    int lowest=0;//极小值
//    bool highter=(rating[0]<rating[1])?true:false;
    bool highter=false;
    for (int i=1;i<quantity;i++)
    {
        if (rating[i-1]<rating[i]&&highter==false)//下降过程中遇到上升 则i-1为极小值的点
        {
            highter=true;
            lowest=i-1;
        }
        else if (highter==true&&rating[i-1]>rating[i])//极大值的点
        {
            for (int j=lefttop;j<lowest;j++)//左极大值到极小值赋值
            {
                candys[j]=((lowest-j+1)<candys[j])?candys[j]:(lowest-j+1);
            }
            for (int j=lowest+1;j<i;j++)//右极大值到极小值赋值
            {
                candys[j]=((j-lowest+1)<candys[j])?candys[j]:(j-lowest+1);
            }
            highter=false;
            lefttop=i-1;
        }
    }
	//剩余部分处理
    if (!highter)
    {
        lowest=quantity-1;
    }
    int i=quantity-1;
        for (int j=lefttop;j<lowest;j++)
        {
            candys[j]=((lowest-j+1)<candys[j])?candys[j]:(lowest-j+1);
        }
        for (int j=lowest+1;j<i;j++)
        {
            candys[j]=((j-lowest+1)<candys[j])?candys[j]:(j-lowest+1);
        }
    for (int k=0;k<quantity;k++)
    {
        cout<<candys[k]<<" ";
    }

}
#endif // CANDY_H_
