#include<bits/stdc++.h>
using namespace std;

float f(float x)
{
    return 1-((100*(3+x))/(9.81*pow((3*x)+((x*x)/2),3)));
}

int main()
{
    float xl=0.5,xu=2.5,x0,e=0.000001;
    int itr=0;
    if(f(xl)*f(xu)>0)
    {
        cout<<"Wrong answer"<<endl;
    }
    do
    {
        x0=xl-((f(xl)*(xl-xu))/(f(xl)-f(xu)));

        if(f(x0)*f(xl)<0)
        {
            xu=x0;
        }
        else
        {
            xl=x0;
        }
        itr++;

        cout<<"Iteration= "<<itr<<", Lower Limit= "<<xl<<", Upper Limit= "<<xu<<", Root= "<<x0<<", f(x0)= "<<f(x0)<<endl;
    }while(fabs(f(x0))>e);
    cout<<"Final root= "<<x0<<endl;
    return 0;
}
