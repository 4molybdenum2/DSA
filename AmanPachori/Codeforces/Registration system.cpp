#include <iostream>
#include<string>
#include<map>
 
using namespace std;
int main() {
  map<string, int> map;
 
  int n,i,k=1,c=0;
  cin>>n;
  int a[n]={0};
  for(i=0;i<n;i++)
  {
      string s;
      cin>>s;
      if(map.find(s)==map.end())
       {cout<<"OK"<<endl;
      map[s]=k;
      k++;}
      else
     {
         a[map[s]]++;
     cout<<s<<a[map[s]]<<endl;
     }
  }
}