#include <iostream>
using namespace std;
int main() {
    int n,r=0,ratio=0,max=0;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    int m;
    cin>>m;
    int b[m];
    for(int i=0;i<m;i++)
    cin>>b[i];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(b[j]%a[i]==0)
            {ratio=b[j]/a[i];
            if(ratio>max)
            {
                max=ratio;
            }}
            else
            continue;            
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(b[j]%a[i]==0)
            {ratio=b[j]/a[i];
            if(max==ratio)
            {
               r++;
            }
            }
            else
            continue;
            
            
        }
    }
cout<<r;
}