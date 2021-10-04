#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,i=0,j=0,k=0;
    cin>>n;
    
     for(i=-n;i<=n;i++)
     {
          int top = n-abs(i);
          for(j=0;j<abs(i);j++)
          cout<<"  ";
          for(k=0;k<top;k++)
          cout<<k<<" ";
          for(k=top;k>0;k--)
          cout<<k<<" ";
          cout<<0<<endl;
     }
     
}