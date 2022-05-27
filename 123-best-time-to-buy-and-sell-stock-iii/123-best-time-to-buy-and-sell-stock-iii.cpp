class Solution {
public:
    int func(int index, bool op, int counter, vector<int>&prices, vector<vector<vector<int>>>&dp) {
        
        if(index == prices.size() || counter == 0)
            return 0;
            
        // if(counter == 0)
        //     return 0;
        if(dp[index][counter][op] != -1)
            return dp[index][counter][op];
        if(op == true) {
     return dp[index][counter][op] = max((func(index+1, false, counter, prices, dp)-prices[index]), func(index+1, op, counter, prices, dp));
        }
        else
     return dp[index][counter][op] = max((func(index+1, true, counter-1, prices, dp)+prices[index]), func(index+1, op, counter, prices, dp));
    }
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        vector<vector<vector<int>>>dp(size+1, vector<vector<int>>(3, vector<int>(4, -1)));
        
        return func(0, true, 2, prices, dp);
    }
};