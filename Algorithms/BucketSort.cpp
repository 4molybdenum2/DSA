#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

void bucketSort(float arr[], int n, int no_buckets){

    // Create n buckets (preferably 'vectors' because they are dynamically resizable) :
    vector<float> bucket[no_buckets];

    float max = *max_element(arr, arr+n);
    float min = *min_element(arr, arr+n);

    //Range of buckets :
    float range = (max - min)/(float)no_buckets;

    // Add each array elements in their respective buckets :
    for(int i=0; i<n; i++){
        float diff = (float)(((arr[i] - min)/(max - min))*no_buckets) - (int)(((arr[i] - min)/(max - min))*no_buckets);

        if(diff == 0 && arr[i] != min){
            bucket[(int)(((arr[i] - min)/(max - min))*no_buckets) - 1].push_back(arr[i]);
        }
        else{
            bucket[(int)(((arr[i] - min)/(max - min))*no_buckets)].push_back(arr[i]);
        }
    }

    //Sort each bucket : (with any sorting algorithm)
    for(int i=0; i<no_buckets; i++){
        if(bucket[i].size()!=0)
            sort(bucket[i].begin(), bucket[i].end());
    }

    // Adding sorted elements back into array from buckets 
    int index = 0;
    for(int i=0; i<no_buckets; i++){
        if(bucket[i].size()!=0){
            for(int j=0; j<bucket[i].size(); j++){
                arr[index++] = bucket[i][j];
            }
        }
    }

}

int main(){
    //Test cases :
    float arr1[10] = {1.32, 9.56, 12.89, 4.52, 0.12, 22.67, 55.61, 0.0, 1.01, 10.00};
    float arr2[10] = {0.23, 7.56, 2.00, 7.02, 0.13, 19.67, 25.61, 0.10, 6.01, 0.55};
    float arr3[10] = {56.32, 9.76, 5.89, 90.52, 0.12, 1.67, 4.7, 0.8, 1.0, 6.60};

    cout<<"Unsorted Array1 :"<<endl;
    for(int i=0; i<10; i++){
        cout<<arr1[i]<<" ";
    }

    bucketSort(arr1, 10, 5);
    cout<<endl;
    cout<<"Sorted Array1 :"<<endl;
    for(int i=0; i<10; i++){
        cout<<arr1[i]<<" ";
    }
    cout<<endl<<endl;
/////////////////////////

    cout<<"Unsorted Array2 :"<<endl;
    for(int i=0; i<10; i++){
        cout<<arr2[i]<<" ";
    }

    bucketSort(arr2, 10, 5);
    cout<<endl;
    cout<<"Sorted Array2 :"<<endl;
    for(int i=0; i<10; i++){
        cout<<arr2[i]<<" ";
    }
/////////////////////////
    cout<<endl<<endl;
    cout<<"Unsorted Array3 :"<<endl;
    for(int i=0; i<10; i++){
        cout<<arr3[i]<<" ";
    }

    bucketSort(arr3, 10, 5);
    cout<<endl;
    cout<<"Sorted Array3 :"<<endl;
    for(int i=0; i<10; i++){
        cout<<arr3[i]<<" ";
    }
    cout<<endl<<endl;
///////////////////////// 
    return 0;
}
/*
Key Notes :
    --> Generally we use Bucket Sort for sorting elements are distributed within a range. Here we have used
    --> 'Count Sort Algorithm' can also be used but it can only be used for integer inputs, for inputs like floating points or double, we will use Bucket Sort.
    --> Complexity of BucketSort is O(n) , considering the sorting of individual buckets as O(1). 
*/