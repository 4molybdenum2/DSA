#include <bits/stdc++.h>
using namespace std;
const int INF = INT_MAX;
const int MAX = 200005;
int main() {
long long int n,m,i,j,k=0,l=0,mn=INF,mx=0;
cin>>n;
long long int a[n];
for(i=0;i<n;i++)
{cin>>a[i];
mn=min(mn,a[i]);
mx=max(mx,a[i]);
}
 
  for ( i = 0; i < n; i++)
    {
        k += (a[i] == mn);
        l += (a[i] == mx);
    }
 
 
 cout<<mx-mn<<" ";
 if(mn==mx)
 cout<<n*(n-1)/2;
 else
 cout<<l*k;
}
