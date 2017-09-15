#ifndef SEARCHINROTATE_H_
#define SEARCHINROTATE_H_

//without duplicates
//an array like this    789123456
template <class T>
int search(T*array,int count,const T&t)
{
    int middle;
    int little=0;
    int big=count-1;
	//每次均保证目标数组在little 和 big之间
    while (little<=big)
    {
        middle=(little+big)/2;
        if (array[middle]==t)
        {
            return middle;
        }
        else if (t<array[count-1])//也就是说在t一个升序的序列中（array原本是升序的）
        {
            if(array[middle]<array[count-1]&&t<array[middle])//middle 在升序当中且比t大则big可以调为 middle-1  （middle在t右边）
            {
                big=middle-1;
            }
			//那么middle在降序中或在升序中但比t小   ，也就是说middle在t左边
            else
            {
                little=middle+1;
            }
        }
        else
        {
            if (array[0]<array[middle]&&array[middle]<t)
            {
                little=middle+1;
            }
            else
            {
                big=middle-1;
            }
        }
    }
    return -1;
}

#endif // SEARCHINROTATE_H_
