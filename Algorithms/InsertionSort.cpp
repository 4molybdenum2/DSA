#include<iostream>
using namespace std;

void InsertionSort(int arr[])
{
    int i=0,j=0,k=0;

    for(i=0;i<7;i++)
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
     int arr[7]= {2,18,7,10,5,6,33};
     InsertionSort(arr);
     // Printing the sorted arrays
     for(int i=0;i<7;i++)
     cout<<arr[i]<<" ";
}