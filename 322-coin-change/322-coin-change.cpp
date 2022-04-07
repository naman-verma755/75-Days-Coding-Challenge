class Solution {
public:
    int findMinCoinChange(int i, vector<int>& coins, int amount, vector<vector<int>>&v) {
        
        // cout<<amount<<" ";
        
        if(amount == 0)
            return 0;
        if(i >= coins.size() || amount < 0)
            return INT_MAX;
        if(v[i][amount] != -1)
            return v[i][amount];
        
        int count1 = findMinCoinChange(i+1, coins, amount, v);
        int count2 = findMinCoinChange(i, coins, amount-coins[i], v);
        if(count2 != INT_MAX)
            count2+=1;
        return v[i][amount] = min(count1, count2);
        
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>v(coins.size()+1, vector<int>(amount+1,-1));
        
        int k = findMinCoinChange(0, coins, amount, v);
        if(k == INT_MAX)
            return -1;
        return k;
        
    }
};