#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        int idx = -1;
        for(int i=0; i<n; i++) {
            if(nums[i] >= 0){
                idx = i;
                break;
            }
        }
        
        // found the index of the first positive element
        int i=idx-1,j=idx;
        while(i >=0 && j < n) {
            if(abs(nums[i]) < nums[j]){
                ans.push_back(nums[i]*nums[i]);
                i--;
            }
            else{
                ans.push_back(nums[j]*nums[j]);
                j++;
            }
        }
        if(idx == -1){
            i = n-1;
            while(i>=0) {
            ans.push_back(nums[i]*nums[i]);
            i--;
            }
            return ans;
        }
        while(i>=0) {
            ans.push_back(nums[i]*nums[i]);
            i--;
        }
        while(j<n){
            ans.push_back(nums[j]*nums[j]);
            j++;
        }
        
        return ans;
    }
};