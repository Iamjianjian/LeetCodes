#ifndef FOURSUM_H_
#define FOURSUM_H_
#include <iostream>
using namespace std;
/*
	参考threesum 不过有duplicate
*/
int nextdiffer(int * array,int index,int quantity)
{
    for(int i=index+1;i<quantity;i++)
    {
        if (array[i]!=array[index])
        {
            return i;
        }
    }
    return -1;
}

int forntnext(int * array,int index)
{
    for (int i=index-1;-1<i;i--)
    {
        if (array[i]!=array[index])
        {
            return i;
        }
    }
    return -1;
}

void foursum(int *array,int quantity,int target)
{
    if(quantity<4)
    {
        return;
    }
	//与threesum 思路相似
    int i=1;
    while (i<quantity-2)
    {
        int j=i+1;
        while (j<quantity-1)
        {
            int f=0;
            int l=quantity-1;
            int temp1;
            int temp2;
            while (f<l)
            {
                if (f==i)
                {
                    f++;
                    continue;
                }
                else if (j==l)
                {
                    l--;
                    continue;
                }
                int sum=array[i]+array[j]+array[f]+array[l];
                if (sum==target)
                {
//                    cout<<array[i]<<array[j]<<array[f]<<array[l]<<endl;
                    cout<<i<<j<<f<<l<<endl;
                }
                if (sum<target)
                {
                    f=nextdiffer(array,f,quantity);
                    if (f==-1)
                    {
                        break;
                    }

                }
                else
                {
                    l=forntnext(array,l);
                    if (l==-1)
                    {
                        break;
                    }
                }
            }
            j=nextdiffer(array,j,quantity);
            if (j==-1)
            {
                break;
            }
        }
        i=nextdiffer(array,i,quantity);
        if (i==-1)
        {
            break;
        }
    }
}
#endif // FOURSUM_H_
