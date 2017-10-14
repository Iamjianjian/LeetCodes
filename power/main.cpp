#include <iostream>

using namespace std;

double power(double x,int n)
{
    if (n==0)
    {
        return 1;
    }

    int temp=1;
    int positive=1;
    if (n<0)
    {
        positive=0;
        n=-1*n;
    }
    int si=sizeof(int)*8;
    int bits[si];
    int i;
    double result=1;
    double np=x;
    for (i=0;i<si;i++)
    {
        if (temp&n)
        {
            bits[i]=1;
            result*=np;
        }
        else
        {
            bits[i]=0;
            result*=1;
        }
        n=n>>1;
        np=np*np;
    }
    if (!positive)
    {
        result=double(1)/result;
    }
    return result;

}

int main()
{
    cout << power(10.0,-2) << endl;
    return 0;
}
