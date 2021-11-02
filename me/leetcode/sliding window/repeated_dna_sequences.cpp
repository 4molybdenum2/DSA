class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.length();
        
        string temp = "";
        unordered_map<string,int> mp;
        for(int i=0; i<10; i++) {
            temp.push_back(s[i]);
        }
        
        mp[temp] = 1;
        int left = 1;
        int right = 10;
        while(right < n) {
            string temp2 = s.substr(left, 10);
            if(mp.find(temp2) != mp.end()) {
                mp[temp2]++;
            }
            else{
                mp[temp2] = 1;
            }
            right++;
            left++;
        }
        
        vector<string> ans;
        for(auto it: mp) {
            if(it.second > 1) ans.push_back(it.first);
        }
        
        return ans;
    }
};