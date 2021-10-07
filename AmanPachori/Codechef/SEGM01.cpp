#include <iostream>

#include<string>

using namespace std;
int main() {
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        int j,k,l=0,m=0;
        for(j=0;j<s.length()-1;j++)
        {
            if(s[j]!=s[j+1])
            {
                l++;
            }
        }
        if(s[0]!='1' & (l<=2 &l>0))
        cout<<"YES"<<endl;
        else if(s[1]=='1'& l<=1)
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;
    }

}
