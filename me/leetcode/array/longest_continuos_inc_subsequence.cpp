class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int max_so_far = 1;
        int ans = 1;
        for(int i=1; i<nums.size(); i++) {
            if(nums[i] > nums[i-1]) {
                max_so_far++;
            }
            else{
                max_so_far = 1;
            }
            ans = max(ans, max_so_far);
        }
        
        return ans;
    }
};