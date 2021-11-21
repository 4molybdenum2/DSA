// WAP to find first negative number in window off size K

typedef long long ll;
typedef long long int lli;

vector<ll> printFirstNegativeInteger(lli A[], lli N, lli K) {
     
     
     // negative is the first negative number in the array or its 0
     vector<ll> ans;
     queue<ll> q;
     
     lli left = 0;
     lli right = 0;
     while(right < N) {
          if(A[right] < 0) {
                q.push(A[right]);
            }
         if(right - left + 1 < K){
            right++;
         }
         else if(right - left + 1 == K) {
            if(!q.empty()) {
                lli node = q.front();
                ans.push_back(node); 
            }
            else{
                ans.push_back(0);
            }
            
            if(A[left] < 0)
                q.pop();
           
            left++;
            right++;
         }
     }
     
     return ans;
 }