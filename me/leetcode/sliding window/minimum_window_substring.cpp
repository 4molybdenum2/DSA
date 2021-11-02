class Solution {
public:
    string minWindow(string s, string t) {
        int n1 = s.length();
        int n2 = t.length();
        
        vector<int> freq(128,0);
        
        for(char ch : t){
            freq[ch]++;
        }
        int count = n2;
        // f is the filtered string
        int left = 0;
        int right = 0;
        int minS = 0;
        int minimum = INT_MAX;
        while(right < n1) {
            if(--freq[s[right++]] >= 0){
                count--;
            }  // no of unique characters in the window
            
            while(count == 0) {
                if(right - left < minimum) {
                    minimum = right - left;
                    minS = left;
                }
                if(++freq[s[left++]] > 0) {
                    count++;
                }
            }
        }
        
        return minimum < INT_MAX ? s.substr(minS, minimum) : "";
    }
};