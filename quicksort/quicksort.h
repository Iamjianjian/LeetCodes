#ifndef QUICKSORT_H_
#define QUICKSORT_H_

template <class T>
void quicksort(T*array,int quantity)
{
    if (quantity==1)
    {
        return ;
    }
    int begin[quantity/2];
    int end[quantity/2];
    int p=0;
    begin[0]=0;
    end[0]=quantity-1;
    int f,l;
    while(p!=-1)
    {
        f=begin[p];
        l=end[p];
        p--;
        int i,j;
        i=f;
        j=l;
        T x=array[i];
        while (i!=j)
        {
            while((x<=array[j])&&(i<j))
            {
                j--;
            }
            if (i<j)
            {
                array[i++]=array[j];
            }
            while ((array[i]<x)&&(i<j))
            {
                i++;
            }
            if (i<j)
            {
                array[j--]=array[i];
            }

        }
        array[i]=x;
        if (f<i-1)
        {
            p++;
            begin[p]=f;
            end[p]=i-1;
        }
        if (i+1<l)
        {
            p++;
            begin[p]=i+1;
            end[p]=l;
        }
    }
}
#endif // QUICKSORT_H_
