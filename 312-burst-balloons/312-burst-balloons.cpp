class Solution {
public:
    int func(int i, int j, vector<int>&v, vector<vector<int>>&dp) {
    // if(i == j)
    //     return v[i];
    if(i > j)
        return 0;
    // cout<<i<<" "<<j<<endl;
    if(dp[i][j] != -1) return dp[i][j];
    int mini = 0;
    for(int index = i; index <= j; index++) {
        int k = v[index]*v[i-1]*v[j+1]+func(i,index-1, v, dp)+func(index+1, j, v, dp);
        mini = max(mini, k);
    }
    return dp[i][j] = mini;
}
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
         vector<int>v;
    v.push_back(1);
    for(int i = 0; i < n; i++)
    {
        int a = nums[i];
        v.push_back(a);
    }
    v.push_back(1);
        vector<vector<int>>dp(n+4, vector<int>(n+4, -1));
    int ans = func(1, n, v, dp);
        return ans;
        
    }
};