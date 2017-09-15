#ifndef MEDIAN_H_
#define MEDIAN_H_
/*
	找两个排序数组的中位数，变为找两个排序数组的第k-1大的数
	
	每个数组折k/2如果不足就全部取，比较k/2的位置的值谁大，小的可以舍去，进入下一次迭代
*/

template <class T>
T find_kth(T*arrm,int m,T*arrn,int n,int k)
{
    if (k==0)//返回小的
    {
        return arrm[0]<arrn[0]?arrm[0]:arrn[0];
    }
    if (k==1)//返回大的
    {
        return arrm[0]<arrn[0]?arrn[0]:arrm[0];
    }
    int t=k/2;
    int mindex,nindex;
    mindex=t;
    nindex=t;
    if (n<t)
    {
        nindex=n-1;
    }
    if (arrm[mindex]==arrn[nindex])
    {
        k-=mindex+nindex+2;
        m-=mindex+1;
        arrm+=mindex+1;
        n-=nindex+1;
        arrn+=nindex+1;
        if (m<n)
        {
            return find_kth(arrn,n,arrm,m,k);
        }
        else
        {
            return find_kth(arrm,m,arrn,n,k);
        }

    }
    else if (arrm[mindex]<arrn[nindex])
    {
        k-=mindex;
        k--;
        m-=mindex+1;
        arrm+=mindex+1;
        if (m==0)//一个数组已经没有元素直接返回另一个数组的对应位
        {
            return arrn[k];
        }
        if (m<n)
        {
            return find_kth(arrn,n,arrm,m,k);
        }
        else
        {
            return find_kth(arrm,m,arrn,n,k);
        }
    }
    else
    {
        k-=nindex+1;
        n-=nindex+1;
        arrn+=nindex+1;
        if (n==0)
        {
            return arrm[k];
        }
        return find_kth(arrm,m,arrn,n,k);
    }

}
#endif // MEDIAN_H_
