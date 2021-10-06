//Main code

#include <iostream>
using namespace std;

#include "solution.h"

int main()
{
	int t;
	cin >> t;
	
	while (t--)
	{
		int size;
		cin >> size;
		int *input = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}

		cout << findDuplicate(input, size) << endl;
	}

	return 0;
}

//Your Code

int findDuplicate(int *arr, int n)
{
    //Write your code here
    int i,j,sum=0,actsum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
    
    }
    for(int j=0;j<n-1;j++)
    {
        actsum+=j;
    }
    int dno=sum-actsum;
    return dno;
}

