#include <iostream>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        if(n%4==1)
        cout<<"EAST"<<endl;
        else if(n%4==2)
        cout<<"SOUTH"<<endl;
        else if(n%4==3)
        cout<<"WEST"<<endl;
        else 
        cout<<"NORTH"<<endl;
    }
}