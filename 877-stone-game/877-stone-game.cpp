class Solution {
public:
    int find(int i, int j, vector<int>&piles,  vector<vector<int>>&dp) {
        
        if(i > j)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        int k1 = piles[i] + min(find(i+2, j, piles, dp), find(i+1, j-1, piles, dp));
        int k2 = piles[j] + min(find(i, j-2, piles, dp), find(i+1, j-1, piles, dp));
        return dp[i][j] = max(k1, k2);
    }
    bool stoneGame(vector<int>& piles) {
        
        vector<vector<int>>dp(piles.size()+1, vector<int>(piles.size()+1, -1));
        int sum = 0;
        for(auto it : piles)
            sum += it;
        
        int k = find(0, piles.size()-1, piles, dp);
        if((sum-k) < k)
            return true;
        else
            return false;
    }
};