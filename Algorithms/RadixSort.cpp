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
    //Test cases :
    int arr1[5] = {5, 10, 7, 64, 1};
    int arr2[5] = {6, 100, 1, 4, 0};
    int arr3[5] = {23, 55, 11, 99, 88};

    cout<<"UnSorted Array1 :"<<endl;
    for(int i=0; i<5; i++){
        cout<<arr1[i]<<" ";
    }

    radixSort(arr1, 5);

    cout<<"\nSorted Array1 :"<<endl;
    for(int i=0; i<5; i++){
        cout<<arr1[i]<<" ";
    }
    cout<<endl<<endl;
/////////////////////////

    cout<<"UnSorted Array2 :"<<endl;
    for(int i=0; i<5; i++){
        cout<<arr2[i]<<" ";
    }

    radixSort(arr2, 5);

    cout<<"\nSorted Array2 :"<<endl;
    for(int i=0; i<5; i++){
        cout<<arr2[i]<<" ";
    }
    cout<<endl<<endl;
///////////////////////////

    cout<<"UnSorted Array3 :"<<endl;
    for(int i=0; i<5; i++){
        cout<<arr3[i]<<" ";
    }

    radixSort(arr3, 5);

    cout<<"\nSorted Array3 :"<<endl;
    for(int i=0; i<5; i++){
        cout<<arr3[i]<<" ";
    }
    cout<<endl<<endl;
/////////////////////////// 
    return 0;
}