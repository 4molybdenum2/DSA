#include<iostream>
#include<climits>
using namespace std;
int main(){
int n;
cin>>n;

int a[100]={0};
for(int i=0;i<n;i++){
    cin>>a[i];
}
int max_sum=0;
int current_sum=0;
for(int i=0;i<n;i++){
    current_sum+=a[i];
    if(current_sum<0){
        current_sum=0;
    }
    max_sum=max(max_sum,current_sum);
}
cout<<max_sum<<endl;
return 0;
}
