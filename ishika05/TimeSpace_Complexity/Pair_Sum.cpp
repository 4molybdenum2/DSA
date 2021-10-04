//Main Code

#include <iostream>
#include <algorithm>
using namespace std;

#include "solution.h"

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int size;
		int x;

		cin >> size;
		int *input = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}

		cin >> x;

		cout << pairSum(input, size, x) << endl;

		delete[] input;
	}
	
	return 0;
}

// Your Code

/*int pairSum(int *arr, int n, int num)
{
	//Write your code here
}*/
int pairSum(int *input, int size, int x)
{
	//Write your code here
     int i,j,count=0;
    for(j=0;j<size;j++)
    {
    for(i=j+1;i<size ;i++)
    {   
        if(input[j]+input[i]==x)
            count++;
    }
    
    }
    return count;
}
