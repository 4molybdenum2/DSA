// max sum subarray of size K
class Solution{   
public:
    int maximumSumSubarray(int K, vector<int> &Arr , int N){
        // code here
        int s = 0;
        for(int i=0; i<K; i++) s += Arr[i];
        
        int ans = s;
        int s_new = s;
        for(int i=K; i<N; i++) {
            s_new = s_new + Arr[i] - Arr[i-K];
            ans = max(ans, s_new);
        }
        
        return ans;
    }
};