#include<bits/stdc++.h>
using namespace std;

float horner(float coeff[],int n,float x)
{
    float p=coeff[0];     //Initialize result

    //Evaluate value of polynomial using Horner's method
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

float f_der(float x)
{
    return 9*x*x - 8*x + 2;
}

int main()
{
    float x0=5.00,x1,e=0.000001;
    int i=0;
    do
    {
        if(f_der(x0)==0.0)
        {
            cout<<"Wrong guess"<<endl;
            break;
        }
        x1=x0-(f(x0)/f_der(x0));
        x0=x1;
        i++;
        cout<<"i= "<<i<<", Root= "<<x0<<", f(x0)= "<<f(x0)<<endl;
    }while(fabs(f(x1))>e);

    cout<<"Final Root= "<<x0<<endl;
    return 0;
}
