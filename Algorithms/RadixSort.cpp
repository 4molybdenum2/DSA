#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

void radixSort(int arr[], int n){
    //Max element in array :
    int max = *max_element(arr, arr+n);
    
    // Create n bins (preferably 'vectors' because they are dynamically resizable) :
    vector<int> bin[10];

    for(int exp = 1; max/exp > 0; exp *=10){
        // Add each array elements in their respective bins :
        for(int i=0; i<n; i++){
            bin[(arr[i]/exp)%10].push_back(arr[i]);
        }

        //Sort each bin : (with any sorting algorithm)
        for(int i=0; i<10; i++){
            sort(bin[i].begin(), bin[i].end());
        }

        // Adding sorted elements back into array from bins 
        int index = 0;
        for(int i=0; i<10; i++){
            for(int j=0; j<bin[i].size(); j++){
                arr[index++] = bin[i][j];
            }
            bin[i].clear();
        }
    }

}

int main(){
    int arr[5] = {5, 10, 7, 64, 1};

    cout<<"Sorted Array :"<<endl;
    for(int i=0; i<5; i++){
        cout<<arr[i]<<" ";
    }

    radixSort(arr, 5);

    cout<<"\nSorted Array :"<<endl;
    for(int i=0; i<5; i++){
        cout<<arr[i]<<" ";
    }
    
    return 0;
}