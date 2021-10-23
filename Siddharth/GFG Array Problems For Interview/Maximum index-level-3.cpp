// Solution for the problem  https://practice.geeksforgeeks.org/problems/maximum-index-1587115620/1

// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.

    int maxIndexDiff(int A[], int N) 
    { 
                                       // Solution code starts here

									   
     long long int i,j,r,k,R=0;    //R to store the maximum index difference to be returned
                                   
        for(i=0;i<N-1;i++)    //outer loop for the ith index element
         {   k=A[i];

            for(j=N-1;j>=i;j--)    //inner loop for maximum index difference for the ith element 
               {  if(A[j]>=k)
                  {   r=j-i;       
                      break;       //breaks the loop
                  }
               }
           
         if(r>R)    // condition for ensuring the maximum index difference is returned
           R=r;

         }   
    return R;

	                                  
									   // Solution code ends here
    }
};


// { Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;

}   // } Driver Code Ends