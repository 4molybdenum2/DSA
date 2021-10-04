#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,m,i,min=10000;
    cin>>n>>m;
    int a[m];
    for(i=0;i<m;i++)
    cin>>a[i];
    
    for(i=0;i<m;i++)
    {
       for(int j=0;j<m;j++)
       if(a[i]<a[j])
       {
           int t=a[i];
           a[i]=a[j];
           a[j]=t;
       }
    }
    for(i=0;i<=m-n;i++)
    {  
        if(a[i+n-1]-a[i]<min)
     {
         
         min=a[i+n-1]-a[i];
    }
    }
cout<<min;
}