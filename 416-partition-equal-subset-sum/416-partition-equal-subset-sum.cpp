class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int size = nums.size();
        int sum = 0;
        for(int i = 0; i < size; i++)
            sum += nums[i];
        if(sum%2 != 0)
            return false;
        int target = sum/2;
        
        bool dp[size+1][target+1];
        for(int i = 0; i <=target; i++) 
            dp[0][i] = false;
        for(int i = 0; i <= size; i++) 
            dp[i][0] = true;
        dp[0][0] = true;
        
        for(int i = 1; i <= size; i++) {
            for(int j = 1; j <= target; j++) {
                
                if(j-nums[i-1] >= 0)
                    dp[i][j] = (dp[i-1][j] || dp[i-1][j-nums[i-1]]);
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[size][target];
        // return false;
        
    }
};