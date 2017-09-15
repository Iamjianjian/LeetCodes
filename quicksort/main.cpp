#include <iostream>
#include "quicksort.h"
using namespace std;

int main()
{
    int j[10]={2,65,45,6,1,5,6,186,4,123};
    quicksort(j,10);
    for (int i=0;i<10;i++)
    {
        cout <<j[i]<<" ";
    }
    return 0;
}
