#include <iostream>
#include "../quicksort/quicksort.h"
#include "threesum.h"
using namespace std;

int main()
{
    int array[10]={28,3,5,15,4,-8,48,-18,-32,564};
    quicksort(array,10);
    for (int i=0;i<10;i++)
    {
        cout << array[i]<<" ";
    }
    cout <<endl;
    threesum(array,10);
    return 0;
}
