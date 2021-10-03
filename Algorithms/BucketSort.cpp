#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

void bucketSort(float arr[], int n){

    // Create n buckets (preferably 'vectors' because they are dynamically resizable) :
    vector<float> bucket[n];

    int max = *max_element(arr, arr+n);
    int min = *min_element(arr, arr+n);

    //Range of buckets :
    int range = (max - min)/range;

    // Add each array elements in their respective buckets :
    for(int i=0; i<n; i++){
        int diff = ((arr[i] - min)/range) - (int)((arr[i] - min)/range);

        if(diff == 0 && arr[i] != min){
            bucket[(int)((arr[i] - min)/range) - 1].push_back(arr[i]);
        }
        else{
            bucket[(int)((arr[i] - min)/range)].push_back(arr[i]);
        }
    }

    //Sort each bucket : (with any sorting algorithm)
    for(int i=0; i<n; i++){
        if(bucket[i].size())
            sort(bucket[i].begin(), bucket[i].end());
    }

    // Adding sorted elements back into array from buckets 
    int index = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<bucket[i].size(); j++){
            arr[index++] = bucket[i][j];
        }
    }

}

int main(){
    //Example array :
    float arr[5] = {1.32, 9.56, 12.89, 4.52, 0.12};

    cout<<"Unsorted Array :"<<endl;
    for(int i=0; i<5; i++){
        cout<<arr[i]<<" ";
    }

    bucketSort(arr, 5);

    cout<<"\nSorted Array :"<<endl;
    for(int i=0; i<5; i++){
        cout<<arr[i]<<" ";
    }
    
    return 0;
}
/*
Key Notes :
    --> Generally we use Bucket Sort for sorting elements are distributed within a range. Here we have used
    --> 'Count Sort Algorithm' can also be used but it can only be used for integer inputs, for inputs like floating points or double, we will use Bucket Sort.
    --> Complexity of BucketSort is O(n) , considering the sorting of individual buckets as O(1). 
*/