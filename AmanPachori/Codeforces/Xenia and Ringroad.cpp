#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
   long long int n,m,crt=1,st=0;
   cin>>n>>m;
   long long int a[m];
   for(int i=0;i<m;i++)
   cin>>a[i];
   for(int i=0;i<m;i++)
   {
         if(a[i]>crt)
        { st+=a[i]-crt;
           crt=a[i];
        }
          else if(a[i]<crt)
         {
             st+= n-crt+a[i];
             crt=a[i];
         }
   }
   cout<<st;
}
