class Solution {
public:
    // recursive - tle
    bool solve(string& s, string& p, int i,int j, vector<vector<int>>& dp) {
        if(i >= s.size()) {
            while(j<p.size()){
                if(p[j]!='*') return dp[i][j] = false;
                j++;
            }
            return dp[i][j] = true;
        }
        else if(j >= p.size())
            return dp[i][j] = false;
        
        else if(dp[i][j] != -1)
            return dp[i][j];
        
        if(s[i] == p[j] || p[j] == '?')
            return dp[i][j] = solve(s,p,i+1,j+1, dp);
        else if(p[j] == '*') {
            return dp[i][j] = solve(s,p,i+1,j, dp) || solve(s,p,i,j+1, dp);
        }
        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size()+1, vector<int>(p.size()+1, -1));
        
        string x = "";
        for(int i=0; i<p.size(); i++){//Removing multiple continuous stars reduced runtime by alot
            x.push_back(p[i]);
            if(p[i]=='*'){
                while(i<p.size() && p[i]=='*') i++;
                i--;
            }
        }
        
        return solve(s,x,0,0, dp);
    }
};