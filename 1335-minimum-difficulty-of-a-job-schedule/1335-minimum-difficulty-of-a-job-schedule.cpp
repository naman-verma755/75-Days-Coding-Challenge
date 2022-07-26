class Solution {
public:
    int func(int i, int j, vector<int>&a, int d, int maxi, vector<vector<vector<int>>>&dp) {
        
        int size = a.size();
        if(j == d) {
            while(i < size) {
                maxi = max(maxi, a[i]);
                i++;
            }
            return maxi;
        }
        if( i == size)
            return 10005;
        
        if(dp[i][j][maxi] != -1)
            return dp[i][j][maxi];
        
        maxi = max(maxi, a[i]);
        int k1 = func(i+1, j, a, d, maxi, dp);
        int k2 = func(i+1, j+1, a, d, 0, dp)+maxi;
        return dp[i][j][maxi] = min(k1, k2);
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int size= jobDifficulty.size();
        if(d > size)
            return -1;
        
        vector<vector<vector<int>>>dp(size+1, vector<vector<int>>(d+1, vector<int>(1005, -1)));
        return func(0, 0, jobDifficulty, d, 0, dp);
    }
};