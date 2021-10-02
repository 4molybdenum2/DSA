#include<iostream>
using namespace std;

void InsertionSort(int arr[],int m)
{
    int i=0,j=0,k=0;

    for(i=0;i<m;i++)
    {
        k=arr[i];
        j=i-1;
        while(j>=0&&arr[j]>k)
        {
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=k;
    }
}

int main()
{
    int n;
    // Enter the size of array//
    cout<<"Enter size of array "<<endl;
    cin>>n;
    int arr[n];
    int i=0;
    // Enter the values in array//
    for(i=0;i<n;i++)
    cin>>arr[i];
     InsertionSort(arr,n);
     // Printing the sorted arrays
     for(int i=0;i<n;i++)
     cout<<arr[i]<<" ";
}