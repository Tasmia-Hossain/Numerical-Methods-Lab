#include<bits/stdc++.h>
#include<math.h>
#include<stdlib.h>
#define error 0.00001
using namespace std;

float f(float p[],int n,float x)
{
    float result=0;
    int i;
    for(i=0;i<=n;i++)
    {
        result=result*x+p[i];
    }
    return result;
}

int main()
{
    cout<<"Enter the highest degree of the equation: ";
    int n,i;
    cin>>n;

    float a,b,x0,x1,x2,f0,f1,f2,e,ds=0.1;

    float coeff[n+1];

    cout<<"\nEnter values of coefficients: ";
    for(i=0;i<=n;i++)
    {
        cout<<"\nCoefficient x^"<<n-i<<"= ";
        cin>>coeff[i];
    }

    float xmax=sqrt(pow((coeff[1]/coeff[0]),2)-2*(coeff[2]/coeff[0]));
    cout<<"Possible interval "<<-xmax<<" and "<<xmax<<endl;
    b=xmax;
    for(a=-xmax;a<=xmax;a+=0.005)
    {
        int itrCount=0;
        int rootCount=1;
        float err;
        x0=a;
        x1=x0+ds;

        cout<<"Number of root \t Approximate root \t Number of Iteration \t Relative Error"<<endl;
        while(x1<b)
        {
            x0=a;
            x1=x0+ds;
            f0=f(coeff,n,x0);
            f1=f(coeff,n,x1);

            if(f0*f1>0)
            {
                //cout<<"Wrong Guess"<<endl;
            }
            else
            {
                do
                {
                    x2=(x0+x1)/2;
                    f2=f(coeff,n,x2);
                    if((f0*f2)<0)
                    {
                        x1=x2;
                    }
                    else
                    {
                        x0=x2;
                    }
                    err=fabs((x1-x0)/x1);

                }while(fabs((x1-x0)/x1)>=error);

                cout<<rootCount<<" \t \t "<<x2<<" \t \t "<<itrCount<<" \t \t \t "<<err<<endl;
                rootCount++;
                if(x1>b)
                {
                    break;
                }
            }
            itrCount++;
            a=x1;
        }
    }
    return 0;;
}
