#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int  n,s,i=0,p=0;
        cin>>n>>s;
       long long int k= (n*(n+1))/2;
       if(k>s)
       p=k-s;
       if(p>=1&&p<=n)
       cout<<p<<endl;
       else
       cout<<-1<<endl;
       }
}
