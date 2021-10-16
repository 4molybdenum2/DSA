#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool doesMatch(vector<int>& mp1, vector<int>& mp2) {
        for(int i=0; i<26;i++) {
            if(mp1[i]!=mp2[i])
                return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        
        if(s1.size() > s2.size())
            return false;
        
        vector<int> mp1(26,0);
        vector<int> mp2(26,0);
        
        for(int i=0; i<n1; i++) {
            mp1[s1[i] - 'a']++;
            mp2[s2[i] - 'a']++;
        }
        
        for(int i=0; i<n2-n1; i++) {
            if(doesMatch(mp1,mp2))
                return true;
            mp2[s2[i+n1] - 'a']++;
            mp2[s2[i] - 'a']--;
        }
        return doesMatch(mp1,mp2);
    }
};