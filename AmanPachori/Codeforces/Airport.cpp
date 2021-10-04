#include <bits/stdc++.h>
using namespace std;
int maxfun(int *arr,int n)
{
    int max=0,j=0;
 
    for(int i=0;i<n;i++)
    {
        if(max<arr[i])
        {
            max=arr[i];
            j=i;
        }   
    }
    arr[j]--;
   return max;
}
int main() {
   int n,m,min=0,max=0;
   cin>>n>>m;
   int k,r;
   k=n;
   r=n;
   int a[m],b[m];
   int i=0,j=0;
   for(i=0;i<m;i++)
    {  cin>>a[i];
       b[i]=a[i];
    }
 
    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        {
            if(a[i]<=a[j])
            {
                int t =a[i];
                a[i]=a[j];
                a[j]=t;
            }
        }
    }   
    i=0;
    while(k>0)
    {
        min+=a[i];
        a[i]--;
        k--;
        if(a[i]==0)
        i++;
         
    }
    while(r>0)
    {
        max+=maxfun(b,m);
        r--;
        
    }
    cout<<max<<" "<<min;
 
 
}
