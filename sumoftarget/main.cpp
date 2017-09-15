#include <iostream>
#include "sumoftarget.h"
using namespace std;

int main()
{
    int i[10]={1,23,5,6,9,7,8,65,2,30};
    st q;
    q=sumoftar(i,10,16);
    cout << "Hello world!" <<q.index1<<q.index2<< endl;
    return 0;
}
