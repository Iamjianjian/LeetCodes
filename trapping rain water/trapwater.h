#ifndef TRAPWATER_H_
#define TRAPWATER_H_
/*
	找出最高的点在从左右计算每个点的接水量（等于前面的另一个最高分的与该点的差值）
*/
int traprainwater1(int *array,int quantity)
{
    int tallest=0;
    for (int i=1;i<quantity;i++)
    {
        if (array[tallest]<array[i])
        {
            tallest=i;
        }
    }
    int water=0;
    int peak;
	//从左边
    for (int i=0,peak=0;i<tallest;i++)
    {
        if (array[i]<peak)
        {
            water+=peak-array[i];
        }
        else
        {
            peak=array[i];
        }
    }
	//从右边
    for (int i=quantity-1,peak=0;tallest<i;i--)
    {
        if (array[i]<peak)
        {
            water+=peak-array[i];
        }
        else
        {
            peak=array[i];
        }
    }
    return water;
}

//记录每个位置左右的最高点，该点的接水量就是两个最高点的小的值减去当前点的值

int traprainwater2(int *array,int quantity)
{
    int leftmax[quantity];
    int rightmax[quantity];
    leftmax[0]=0;
    rightmax[quantity-1]=0;
	//计算最高点
	
    for (int i=1;i<quantity;i++)
    {
        leftmax[i]=(leftmax[i-1]<array[i-1])?array[i-1]:leftmax[i-1];
        rightmax[quantity-1-i]=(rightmax[quantity-i]<array[quantity-i])?array[quantity-i]:rightmax[quantity-i];
    }
    int water=0;
	//计算接水量
	
    for (int i=1;i<quantity-1;i++)
    {
        int temp;
        temp=(leftmax[i]<rightmax[i])?leftmax[i]:rightmax[i];
        water+=(temp<array[i])?0:temp-array[i];
    }
    return water;
}
#endif // TRAPWATER_H_
