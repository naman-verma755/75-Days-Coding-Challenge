class Solution {
public:
    bool func(int i, int j, int k, string s1, string s2, string s3, vector<vector<int>>&dp) {
        
        // if(res == s3 && i == s1.length() && j == s2.length())
        //     return true;
        if(i == s1.length() )
        {
            // cout<<s2.substr(j)<<" "<<s3.substr(k)<<endl;
            return (s2.substr(j) == s3.substr(k));
        }
        if(j == s2.length()) {
            // cout<<s1.substr(i)<<" "<<s3.substr(k)<<endl;
            return (s1.substr(i) == s3.substr(k));
        }
        if(dp[i][j] != -1)
            return dp[i][j];
        bool ans = false;
if((s1[i] == s3[k] && func(i+1, j, k+1, s1, s2, s3,dp )) || (s2[j] == s3[k] && func(i, j+1, k+1, s1, s2, s3,dp ) ))
        ans = true;
    
        return dp[i][j] = ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        
        vector<vector<int>>dp(s1.length()+1, vector<int>(s2.length()+1, -1));
       
        return func(0, 0,0, s1, s2, s3, dp);
        
    }
};