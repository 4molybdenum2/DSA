// Solution for the problem  https://practice.geeksforgeeks.org/problems/peak-element/1#


// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


               /* The function should return the index of any peak element present in the array */

      // arr: input array
      // n: size of array

class Solution

{
    public:
    int peakElement(int arr[], int n)
   {

                                             // solution code starts here



   int i,cn=0;       //cn is variable to store the index that we have to return
       
   if(n==1)             /*if the array is of size 1 then the only element which present in the array at index 0
                                     will be the peak element*/
       cn=0;


   else
     { 
        if(arr[0]>arr[1])      //edge case for the first element
          cn=0;
        
        else if(arr[n-1]>arr[n-2])      //edge case for the last element
          cn=n-1;

        else
      
         for(i=1;i<n-1;i++)      // for checking the condition for the rest of the elements

             if(arr[i]>arr[i-1] && arr[i]>arr[i+1])
                    { 
                      cn=i;    
                      break;
                    } 
      }

   return cn;      //returning the index of the peak element



                                           // solution code ends here
   }

};

// { Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n], tmp[n];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			tmp[i] = a[i];
		}
		bool f=0;
		Solution ob;
		
		int A = ob. peakElement(tmp,n);
		
		if(A<0 and A>=n)
		    cout<<0<<endl;
		else
		{
		if(n==1 and A==0)
		f=1;
		else
		if(A==0 and a[0]>=a[1])
		f=1;
		else if(A==n-1 and a[n-1]>=a[n-2])
		f=1;
		else if(a[A]>=a[A+1] and a[A]>= a[A-1])
		f=1;
		else
		f=0;
		cout<<f<<endl;
		}
		
	}

	return 0;
}  

// } Driver Code Ends