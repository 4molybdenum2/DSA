class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0)); // define a vector of the same shape initialized to zeros
        
        // now to calculate the minimum path sum ...we iterate over the diagonals and fill in the necessary minimum values in every square taking into account the values in the previous diagonal.
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i == 0 && j==0)
                    dp[i][j] = grid[i][j];
                else
                    dp[i][j] = min((j>0?dp[i][j-1]:INT_MAX) , (i>0?dp[i-1][j]:INT_MAX)) 
                    + grid[i][j];
            }
        }
        return dp[m-1][n-1];
    }
};