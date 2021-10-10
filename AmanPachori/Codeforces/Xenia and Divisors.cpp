#include<iostream>
using namespace std;
 
int main() {
  int n;
  cin>>n;
  int a[8]={0};
  int i=0,j=0;
  for(i=0;i<n;i++)
  {
      int h;
      cin>>h;
      a[h]++;
  }
  if(a[5]==0&&a[7]==0&&a[2]>=a[4]&&a[1]==a[4]+a[6]&&a[2]+a[3]==a[4]+a[6])
  {
      for(i=0;i<a[4];i++)
        {
            cout<<"1 2 4"<<endl;
        }
 
        a[2]=a[2]-a[4];
 
      for(i=0;i<a[2];i++)
        cout<<"1 2 6"<<endl;
      for(i=0;i<a[3];i++)
        cout<<"1 3 6\n";
 
  }
  else
  {
    cout<<"-1";
  }
 
}