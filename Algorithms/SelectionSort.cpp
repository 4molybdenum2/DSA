#include<iostream>
using namespace std;

void selectionSort(int a[],int m)
{
  int i=0,j=0,k=0;
  for(i=0;i<m;i++)
  {
     int min =i;
     for(j=i+1;j<m;j++)
     {
         if(a[j]<a[min])   // for sorting the array in descending oreder just replace '<' to '>''//
         {
             min=j;
         }
     } 
     if(min!=i)
     {
         int temp;
         temp=a[min];
         a[min]=a[i];
         a[i]=temp;
     }
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

    selectionSort(arr,n);
    for(i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

}