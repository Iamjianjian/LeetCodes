#ifndef SINGLEBUMBERTWO_H_
#define SINGLEBUMBERTWO_H_


/*
	对于一个数组某些只有一个元素只出现了一次
	其他出现了三次，找出这个元素
*/
int func1(int *array,int quantity)
{
	/*方法一用一个数组记录各个int的各个bit*/
    const int w=sizeof(int)*8;//一个字节8bit
    int bits[w];
    for (int i=0;i<w;i++)
    {
        bits[i]=0;
    }
	//各个bit 加起来 在mod3
	
    for (int i=0;i<quantity;i++)
    {
        int temp=array[i];
        for (int j=0;j<w;j++)
        {
            bits[j]+=temp&1;
            temp=temp>>1;
        }
    }
    int result=0;
    for(int i=0;i<w;i++)
    {
        result+=(bits[i]%3)<<i;

    }
    return result;
}

int func2(int *array,int quantity)
{
	/*用one two 的各个bit记录array中各个数字的bit mod3  也就是模拟一个3"异或"*/
    int one=0,two=0;
    for (int i=0;i<quantity;i++)
    {
        two|=(one&array[i]);
        one^=array[i];
        int three=two&one;//one 和 two 都有 则mod3
        one^=three;
        two^=three;
    }
    return one+two;
}
#endif // SINGLEBUMBERTWO_H_
