#include <iostream>
#include "median.h"
using namespace std;

int main()
{
    int a[5]={1,2,3,5,9};
    int b[7]={10,11,23,56,100,200,300};
    find_kth(b,7,a,5,4);
    cout << "Hello world!" <<find_kth(b,7,a,5,4)<< endl;
    return 0;
}
