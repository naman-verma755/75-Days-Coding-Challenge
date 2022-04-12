class Solution {
public:
  
    int numRollsToTarget(int n, int k, int target) {
        int mod = 1000000007;

        vector<int>prev(target+1,0);
        
        prev[0] = 1;
      
        vector<int>curr(target+1, 0);
        for(int i = 1; i <= n; i++) {
            
            for(int j = 1; j <= target; j++) {
                curr[j] = 0;
                for(int e = 1; e <= k; e++) {
                    if(e <= j)
                    curr[j] = (curr[j]%mod+prev[j-e]%mod)%mod;
                  
                    
                }
            }
            prev = curr;
        }
        return prev[target];

        
    }
};