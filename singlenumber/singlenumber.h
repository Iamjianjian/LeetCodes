#ifndef SIGNLENUMBER_H_
#define SIGNLENUMBER_H_
/*
	一个数组只有一个元素只出现了一次
	其他的两次
	找出该元素
	
	直接异或可得 复杂度 n
*/
int singlenumber(int *array,int quantity)
{
    int result=array[0];
    for (int i=1;i<quantity;i++)
    {
        result^=array[i];
    }
    return result;
}
#endif // SIGNLENUMBER_H_
