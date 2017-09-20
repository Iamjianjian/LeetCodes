#include <stdio.h>
#include <string.h>
#include <malloc.h>

char *multiply(char *num1,char*num2)
{
    int l1=strlen(num1);
    int l2=strlen(num2);
    char *result=(char*)malloc(l1+l2+1);
    result[l1+l2]='\0';
    int i,j;
    int temp;
    int t;
    for (i=0;i<l1+l2;i++)
    {
        result[i]='0';
    }
    for (i=l1-1;0<=i;i--)
    {
        temp=0;
        for (j=l2-1;0<=j;j--)
        {

            t=(num1[i]-'0')*(num2[j]-'0');
            t+=temp;
            t+=result[i+j+1]-'0';
            temp=t/10;
            t=t%10;
            result[i+j+1]=(char)('0'+t);
        }
        while (temp!=0)
        {
            t=temp+result[i+j+1]-'0';
            result[i+j+1]=t%10+'0';
            temp=t/10;
            j--;
        }
    }
    i=0;
    while (result[i]=='0'&&i<(l1+l2-1))
    {
        i++;
    }
    return result+i;

}

int main()
{
    printf("%s\n",multiply("0","0"));
    return 0;
}
