#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int n,m,k=0;
    cin>>n>>m;
    int a[n],b[n];
    for(int i=0;i<n;i++)
    {cin>>a[i];
    b[i]=a[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(b[i]>b[j])
            swap(b[i],b[j]);
        }
    }
    for(int i=0;i<m;i++)
    if(b[i]<=0)
    {k+=b[i];}
    k=abs(k);
    cout<<k;
 
}