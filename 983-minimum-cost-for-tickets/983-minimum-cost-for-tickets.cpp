class Solution {
public:
    int findMin(int maxi, vector<int>&days, vector<int>&costs, map<int, int>&mp) {
        
          if(maxi < 0)
              return 0;
        
          if(!mp.count(maxi)) {
              return findMin(maxi-1, days, costs, mp);
          } else {
              
              int a = findMin(maxi-1, days, costs, mp)+costs[0];
              int b = findMin(maxi-7, days, costs, mp)+costs[1];
              int c = findMin(maxi-30, days, costs, mp)+costs[2];
              
              return min(a, min(b,c));
          }
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        int maxi = 0;
        map<int, int>mp;
        for(int it : days) {
            maxi = max(it, maxi);
            mp[it] ++;
        }
        vector<int>dp(maxi+2, 0);
        
        for(int i = 1; i <= maxi; i++) {
            
            if(mp.count(i)) {
                // cout<<i<<" ";
                int mini = INT_MAX;
               int a = costs[0], b = costs[1], c = costs[2];
                if(i-1 >= 0) 
                    a += dp[i-1];
                if(i-7 >= 0)
                    b += dp[i-7];
                if(i-30 >= 0)
                    c += dp[i-30];
                // if(mini != INT_MAX)
                dp[i] = min(a, min(b,c));
            }
            else
                dp[i] = dp[i-1];
        }
        // for(auto it : dp)
        //     cout<<it<<" ";
        return dp[maxi];
        // return findMin(maxi, days, costs, mp);
        
        
    }
};