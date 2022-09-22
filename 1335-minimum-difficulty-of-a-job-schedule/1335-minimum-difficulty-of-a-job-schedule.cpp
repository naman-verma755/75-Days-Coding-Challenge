class Solution {
public:
    int func(int index, int maxi, int day, vector<int>& jDiff, int D, vector<vector<vector<int>>>&dp) {
        int n = jDiff.size();
          if(index == n )
            return 10005;
        if(day == D) {
            while(index < n){
                maxi = max(jDiff[index], maxi);
                index++;
            }
            return maxi;
        }
      
        if(dp[index][day][maxi] != -1)
            return dp[index][day][maxi];
        maxi = max(maxi, jDiff[index]);
        int k1 = func(index+1, maxi, day, jDiff, D, dp);
        int k2 = func(index+1, 0, day+1, jDiff, D,  dp) + maxi;
        return dp[index][day][maxi] = min(k1, k2);
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        
        int n = jobDifficulty.size();
        if(n < d)
            return -1;
        vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(d+1, vector<int>(1005, -1)));
        
        return func(0, 0, 1, jobDifficulty, d, dp);
    }
};