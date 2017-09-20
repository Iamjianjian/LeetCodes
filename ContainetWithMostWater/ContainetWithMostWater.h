#ifndef CONTAINER_H_
#define CONTAINER_H_

/*
    https://leetcode.com/problems/container-with-most-water/description/

     Ë¼Â·ÔÚsolution
*/
int func(int *line,int quantity)

{

    int maxmum=0;
    int l,r;
    int temp;
    for (l=0,r=quantity-1;l!=r;)
    {
        temp=(r-l)*((line[l]<line[r]):line[l]:line[r]);
        maxnum=(maxmum<temp)?temp:maxmum;
        if(line[l]<line[r])
        {
            l++;
        }
        else
        {

            r--;
        }
    }
    return maxmum;
}
#endif // CONTAINER_H_
