#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    while(n--)
    {
        long int m,k,ma=0,ind=0,ans=0;
        cin>>m>>k;
       long int a[m+1];
        for(int i=1;i<=m;i++)
        {
            cin>>a[i];
            ma = max(ma,a[i]);
        }
        for(int i=k;i<=m;i++)
        {
            if (ma==a[i])
              ans+=m+1-i;
        }
        cout<<ans<<endl;

    }
}