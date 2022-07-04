class Solution {
public:
    string func(int i, int j, string s1, string s2, string res, vector<vector<string>>&dp) {
        
        int len1 = s1.length();
        int len2 = s2.length();
        
        if(i == len1)
           return res += s2.substr(j, len2);
        if(j == len2)
           return res += s1.substr(i, len1);
        
        if(dp[i][j] != "-1")
            return dp[i][j];
        if(s1[i] == s2[j]) 
            return dp[i][j] = func(i+1, j+1, s1, s2, res+s1[i], dp);
        else {
            string str1 = func(i+1, j, s1, s2, res+s1[i], dp);
            string str2 = func(i, j+1, s1, s2, res+s2[j], dp);
            if(str1.length() < str2.length())
                return dp[i][j] = str1;
            else
            return dp[i][j] = str2;
        }
        return "";
    }
    string shortestCommonSupersequence(string str1, string str2) {
        // vector<vector<string>>dp(str1.length()+1, vector<string>(str2.length()+1, "-1"));
        int len1 = str1.length(), len2 = str2.length();
        int dp[len1+1][len2+1];
        
        for(int i = 0; i < len1; i++) 
            dp[i][0] = 0;
        for(int i = 0; i < len2; i++)
            dp[0][i] = 0;
        
        for(int i = 1; i <= len1; i++) {
            for(int j = 1; j <= len2; j++) {
                
                if(str1[i-1] == str2[j-1])
                    dp[i][j] = dp[i-1][j-1]+1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
//           for(int i = 0; i <= len1; i++) {
//             for(int j = 0; j <= len2; j++) {
                
//                cout<<dp[i][j]<<" ";
//             }
//               cout<<endl;
//         }
        
        int i,j;
        string ans = "";
         for( i = len1,j=len2; i >= 1&&j>=1; ) {
            
                // cout<<i<<" "<<j<<endl;
                if(str1[i-1] == str2[j-1])
                {
                    ans += str1[i-1];
                    i--,j--;
                }
                else if(dp[i-1][j] > dp[i][j-1]) {
                    ans += str1[i-1];
                    i--;
                    
                }
                else
                {
                    ans += str2[j-1];
                    j--;
                }
            
        }
        
          while(i > 0)
              ans += str1[i-1],i--;
        while(j > 0)
            ans += str2[j-1],j--;
        
        
         reverse(ans.begin(), ans.end());
        return ans;
    }
};