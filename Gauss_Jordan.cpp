#include<bits/stdc++.h>
#define MAX 10
using namespace std;

void gauss_jordan(int n,double matrix[MAX][MAX+1] )
{
    int i,j,k;
    double pivot,factor;
    for(i=0;i<n;i++)
    {
        pivot=matrix[i][i];
        for(j=i;j<=n;j++)
        {
            matrix[i][j]=matrix[i][j]/pivot;
        }
        for(k=0;k<n;k++)
        {
            if(k!=i)
            {
                factor=matrix[k][i];
                for(j=i;j<=n;j++)
                {
                    matrix[k][j]=matrix[k][j]-factor*matrix[i][j];
                }
            }
        }
    }
}

int main()
{
    int n,i,j;
    cout<<"Enter Number of equations: ";
    cin>>n;

    double matrix[MAX][MAX+1];

    cout<<"Input matrix:"<<endl;
    for(i=0;i<n;i++)
    {
        for(j=0;j<=n;j++)
            cin>>matrix[i][j];
    }

    gauss_jordan(n,matrix);

    for(i=0;i<n;i++)
    {
        cout<<"x"<<i+1<<"= "<<matrix[i][n]<<endl;
    }
//        cout<<"x= "<<matrix[0][n]<<endl;
//        cout<<"y= "<<matrix[1][n]<<endl;
//        cout<<"z= "<<matrix[2][n]<<endl;
}
