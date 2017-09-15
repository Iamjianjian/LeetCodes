#ifndef THREESUM_H_
#define THREESUM_H_
#include <iostream>
#include "../quicksort/quicksort.h"
using namespace std;

/*
	给定数组(without duplicates)找出三个数的和为0，不能重复

	先排序nlgn
	在遍历i ，f和n两边逼近n**2
*/
void threesum(int *array,int quantity)
{
    if (quantity<3)
    {
        return;
    }
	//因为f和n从两边逼近，i 从1 到quantity-2
    for (int i=1;i<quantity-1;i++)
    {
        int f,n;
        f=0;
        n=quantity-1;
        int sum;
		//f和 n都不能越过i，否则重复
        while (f!=i&&n!=i)
        {
            sum=array[f];
            sum+=array[i];
            sum+=array[n];
            if (sum==0)
            {
                cout<<array[f]<<"  "<<array[i]<<"  "<<array[n]<<endl;
                f++;
                n--;

            }
            else if (sum<0)
            {
                f++;
            }
            else
            {
                n--;
            }

        }
    }
}
#endif // THREESUM_H_
