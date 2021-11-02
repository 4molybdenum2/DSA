class Solution {
public:
    string simplifyPath(string path) {
        int n = path.size();
        vector<string> st;
        int t = 1;
        for(int i=1; i<n; i++) {
            if(path[i] == '/') {
                string temp = path.substr(t,i-t);
                t = i+1;
                if(temp == "" || temp == "."){
                    continue;
                }
                else if(temp == "..") {
                    if(!st.empty())
                        st.pop_back();
                }
                else{
                    st.push_back(temp);
                }
            }
            
            else if(i == n-1) {
                string temp = path.substr(t,i-t+1);
                if(temp == "" || temp == "."){
                    continue;
                }
                else if(temp == "..") {
                    if(!st.empty())
                        st.pop_back();
                }
                else{
                    st.push_back(temp);
                }
            }
            
        }
        string ans = "/";
        for(int i=0; i<st.size(); i++) {
            ans = ans + st[i] + "/";
        }
        
        if(ans.size() > 1) {
            ans = ans.substr(0,ans.size()-1);
        }
        return ans;
    }
};