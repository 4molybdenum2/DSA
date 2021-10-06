//Main Code

#include <iostream>
using namespace std;

#include "solution.h"

int main() {
    int t;
    cin >> t;

    while (t--) {
        int size;
        cin >> size;
        int *input = new int[size];

        for (int i = 0; i < size; ++i) {
            cin >> input[i];
        }

        cout << findUnique(input, size) << endl;
    }

    return 0;
}

//Your code

int findUnique(int *arr, int n) {
    // Write your code here
     int Xor = arr[0];
        for (int i = 1; i < n; i++)
         Xor = Xor ^ arr[i];
 
        return Xor;
    
    
   /* int i,j;
    for(i=0;i<n;i++)
    {   int c=0;
    for(j=0;j<n&&j!=i;j++)
        if (arr[i]==arr[j])
        {
            c++;
        } 
          if(c==0)
     {
         cout << arr[i]<<endl;
     }
    
    }*/
    
   
    
}

