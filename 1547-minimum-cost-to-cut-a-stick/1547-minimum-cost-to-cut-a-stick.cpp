class Solution {
public:
    int func(int start, int end, int i, int j, vector<int>&cuts, vector<vector<int>>&dp) {
        
        if(i > j)
            return 0;
        int mini = INT_MAX;
        // cout<<end-start<<" ";
        if(dp[i][j] != -1)
            return dp[i][j];
        for(int ind = i; ind <= j; ind++) {
            int k = end-start + func(start,cuts[ind], i, ind-1, cuts, dp)+func(cuts[ind], end, ind+1, j, cuts, dp);
            mini = min(mini, k);
        }
        return dp[i][j] = mini;
    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        vector<vector<int>>dp(cuts.size()+1, vector<int>(cuts.size()+1, -1));
        return func(0, n, 0, cuts.size()-1, cuts, dp);
    }
};