class Solution {
public:
    int dp[2501];
    int solve(vector<int>& nums, int lg, int idx) {
        if(idx >= nums.size())
            return 0;
        
        if(dp[idx] != -1)
            return dp[idx];
        int ans = 0;
        for(int i=idx; i<nums.size(); i++) {
            if(nums[i] > lg) {
                ans = max(ans, 1 + solve(nums, nums[i], i+1));
            }
        }
        return dp[idx] = ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        int ans = solve(nums,INT_MIN, 0);
        return ans;
    }
};