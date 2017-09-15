#include <iostream>
#include "searchinrotatearray.h"
using namespace std;

int main()
{
    int i[10]={6,7,8,9,10,1,2,3,4,5};
    int j=search(i,10,3);
    cout << j<<endl;
    return 0;
}
