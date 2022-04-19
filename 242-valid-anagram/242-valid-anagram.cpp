class Solution {
public:
    bool isAnagram(string s, string t) {
        
        int dp1[27] = {};
        // int dp2[27] = {};
        for(auto it : s)
            dp1[it-'a'] ++;
        for(auto it : t) 
            dp1[it-'a'] --;
        for(int i = 0; i < 27; i++)
        {
            if(dp1[i] != 0)
                return false;
        }
        return true;
    }
};