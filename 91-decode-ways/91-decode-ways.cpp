class Solution {
public:
     
//     int findWays(int index, string s,  vector<int>&dp ){
//         if(index == s.length())
//             return 1;
        
//         if(s[index] == '0')
//             return 0;
        
//          if(dp[index] != -1)
//              return dp[index];
//         int count = 0;
//         count += findWays(index+1, s, dp);
//         string res = "";
//         if(index+1 < s.length()) {
//         res = res+s[index]+s[index+1];
//         if(res >= "10" && res <= "26")
//             count += findWays(index+2, s, dp);
//         }
        
//         return dp[index] = count;
        

//     }
    int numDecodings(string s) {
        int dp[s.length()+1];
        dp[0] = 1;
        if(s[0] != '0')
            dp[1] = 1;
        else
            dp[1] = 0;
        
        for(int i = 2; i <= s.length(); i++) {
            int count = 0;
            if(s[i-1] != '0') {
                count += dp[i-1];
            }
          
            string res = "";res = res+s[i-2]+s[i-1];
            if(res >= "10" && res <= "26") {
                count += dp[i-2];
            }
            
            dp[i] = count;
        }
        return dp[s.length()];
        // return findWays(0, s, dp);
    }
};