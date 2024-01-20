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

float g(float x)
{
    return sqrt((3*x+7)/2);
}

int main()
{
    float x0,x1,e;
    int N;
    cout<<"Enter initial guess: ";
    cin>>x0;

    cout<<"Enter tolerable error: ";
    cin>>e;

    cout<<"Enter maximum iteration: ";
    cin>>N;

    int step=0;
    do
    {
        x1=g(x0);
        step++;
        if(step>N)
        {
            cout<<"Not Convergent"<<endl;
            break;
        }
        x0=x1;
        cout<<"i= "<<step<<", Root= "<<x0<<", f(x0)= "<<f(x0)<<endl;
    }while(fabs(f(x1))>e);
    cout<<"Root: "<<x0<<endl;
    return 0;
}
