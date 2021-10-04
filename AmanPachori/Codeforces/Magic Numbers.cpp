#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
 
int main()
{
   string s;
   cin>>s;
   int c=0,i;
 
   for(i=0;i<s.size();i++)
   {
       if(s[i]=='1'&&s[i+1]=='4'&&s[i+2]=='4')
       i+=2;
       else if(s[i]=='1'&&s[i+1]=='4')
       i+=1;
       else if(s[i]=='1')
       continue;
       else
       c++;
   }
   if(c!=0)
   cout<<"NO";
   else
   cout<<"YES";
}