class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();
        // the solution is basically first remove excess closed braces from the original string, then excess closed braces from the reversed version of the first result.
        string ans = "";
        int open = 0;
        for(int i=0; i<n; i++) {
            if(s[i] == '(') {
                open++;
            }
            else if(s[i] == ')'){
                if(open > 0) {
                    open--;
                }
                else{
                    continue;
                }
            }
            ans.push_back(s[i]);
            
        }
        if(open == 0) return ans;
        
        int n2 = ans.size();
        string ans2 = "";
        open = 0;
        for(int i=n2-1; i>=0; i--) {
            if(ans[i] == ')') {
                open++;
            }
            else if(ans[i] == '('){
                if(open > 0) {
                    open--;
                }
                else{
                    continue;
                }
            }
            ans2.push_back(ans[i]);
            
        }
        reverse(ans2.begin(), ans2.end());
        return ans2;
        
    }
};