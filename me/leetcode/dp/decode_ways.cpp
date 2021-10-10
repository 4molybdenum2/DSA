class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        int dp[n+1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        dp[1] = s[0] == '0' ? 0 : 1;
        for(int i=2; i<=n; i++) {
            int first = s[i-1] - '0';
            int second = stoi(s.substr(i-2, 2));
            if(first >= 1)
                dp[i] = dp[i-1] + dp[i]; // this is the no. of ways to decode string if the string ended at ith index, if at any point an index becomes 0 there is no way to decode the string from there considering only single digits
            if(second >=10 && second <=26)
                dp[i] = dp[i-2] + dp[i]; // this is the no. of ways to decode the string considering only two digits, as w already added the values for 1 index previously all the cases get added up
        }
        
        return dp[n];
    }
};