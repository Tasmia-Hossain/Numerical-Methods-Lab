#include<bits/stdc++.h>
using namespace std;

float horner(float coeff[],int n,float x)
{
    float p=coeff[0];
    for(int i=1;i<n;i++)
        p=p*x+coeff[i];

    return p;
}

float f(float x)
{
    float coeff[]={3,-4,2,-7};
    int degree=sizeof(coeff)/sizeof(coeff[0]);
    return horner(coeff,degree,x);
}

int main()
{
    float x0=2.0,x1=3.0,x2,e=0.000001;
    int i=0;
    do
    {
        x2=x0-(f(x0)*(x0-x1))/(f(x0)-f(x1));
        x0=x1;
        x1=x2;
        i++;
        cout<<"i= "<<i<<", Root= "<<x0<<", f(x0)= "<<f(x0)<<endl;
    }while(fabs(f(x2))>e);
    cout<<"Final Root= "<<x0<<endl;
    return 0;
}
