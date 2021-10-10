#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int prev_max = nums[0];
        int prev_min = nums[0];
        int overall_max = nums[0];
        for(int i=1; i<n; i++) {
            int curr = nums[i];
            int curr_max = max({curr, prev_max*curr, prev_min*curr});
            int curr_min = min({curr, prev_max*curr, prev_min*curr});
            overall_max = max(curr_max, overall_max);
            prev_max = curr_max;
            prev_min = curr_min;
        }
        return overall_max;
    }
};