#ifndef SUMOF_H_
#define SUMOF_H_
#include <iostream>
using namespace std;
/*
	给定非负数组，和正数target 找出和为target的两个数
*/
struct st
{
    int index1;
    int index2;
};
st sumoftar(int *array,int leng,int target)
{
    st temp;
	//记录该数字是否出现过
    bool isempty1[target/2];
    bool isempty2[target/2];
    for (int i=0;i<target/2;i++)
    {
        isempty1[i]=false;
        isempty2[i]=false;
    }
	//记录出现过的数字的索引
    int indexs1[target/2];
    int indexs2[target/2];

        for (int i=0;i<leng;i++)
        { 	//因为数组非负大于舍去
            if (array[i]>=target||array[i]==0)
            {
                continue;
            }
			//数字出现时记录位置在看对应的另一个数是否出现过
            if (array[i]<=target/2&&isempty1[array[i]-1]==false)
            {
                isempty1[array[i]-1]=true;
                indexs1[array[i]-1]=i;
                if (isempty2[array[i]-1]==true)
                {
                    temp.index1=i;
                    temp.index2=indexs2[array[i]-1];
                    return temp;
                }
            }
            else if (array[i]==target/2&&isempty1[array[i]-1]==true)
            {
                temp.index2=i;
                temp.index1=indexs1[array[i]-1];
                return temp;
            }
            else if (target/2<array[i]&&isempty2[target-array[i]-1]==false)
            {
                isempty2[target-array[i]-1]=true;
                indexs2[target-array[i]-1]=i;
                if (isempty1[target-array[i]-1]==true)
                {
                    temp.index1=indexs1[target-array[i]-1];
                    temp.index2=i;
                    return temp;
                }
            }
        }
    temp.index1=-1;
    temp.index2=-1;
    return temp;

}
#endif // SUMOF_H_
