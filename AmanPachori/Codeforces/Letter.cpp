#include <bits/stdc++.h>
using namespace std;
int main() {
  string s1,s2;
  int h=0,i;
  getline(cin,s1);
 getline(cin,s2);
  map<char,int> t;
  for(i=0;i<s1.length();i++)
  {
      t[s1[i]]++;
  }
  for(i=0;i<s2.length();i++)
  {
      if(t[s2[i]]>0||s2[i]==' ')
      {
          t[s2[i]]--;
          continue;
      }
      else
      {
        h++;
      }
  }
  if(h>0)
  cout<<"NO";
  else
  cout<<"YES";
}
