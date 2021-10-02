#include<iostream>
using namespace std;

void selectionSort(int a[])
{
  int i=0,j=0,k=0;
  for(i=0;i<7;i++)
  {
     int min =i;
     for(j=i+1;j<7;j++)
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
    int arr[7]={3,6,1,5,4,9,2};
    int i=0;
    selectionSort(arr);
    for(i=0;i<7;i++)
    {
        cout<<arr[i]<<" ";
    }

}