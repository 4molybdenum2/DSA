// Solution for the problem  https://practice.geeksforgeeks.org/problems/cyclically-rotate-an-array-by-one2614/1


// { Driver Code Starts

#include <stdio.h>

void rotate(int arr[], int n);

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int a[n] , i;
        for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        rotate(a, n);
        for (i = 0; i < n; i++)
            printf("%d ", a[i]);
        printf("\n");
    }
        return 0;
}

// } Driver Code Ends


void rotate(int arr[], int n)
{ 

	                          // solution code starts here

  int i,temp;     /* we declare temp variable to store the last element of 
                        array to later transfer it at the first position*/
     
    temp=arr[n-1];
   
    for(i=n-1;i>0;i--)    //cyclically rotating all elements but the first element is still left
         arr[i]=arr[i-1];
    
    arr[0]=temp;         //assigning first element the value of the last element
	 
	                         // solution code ends here
}