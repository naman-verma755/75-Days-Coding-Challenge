class Solution {
public:
    
     bool isPalindrome(string &s, map<string, int>&mp) {
        // if(mp.count(s))
        //     return true;
        int i = 0, j = s.length()-1;
        while(i < j) {
            if(s[i++] != s[j--])
            return false;
        }
        
        return true;
    }
    int find(string str, map<string, int>&mp) {
        
        if(str.length() <= 0)
        return 0;
        
        if(mp.count(str))
        return mp[str];
        if(isPalindrome(str, mp))
            return mp[str] = 0;
        int mini = INT_MAX;
        string res = "";
        for(int i = 0; i < str.length(); i++) {
            res += str[i];
            if(isPalindrome(res, mp)) {
                int k = find(str.substr(i+1, str.length()), mp)+1;
                mini = min(mini, k);
            }
        }
        return mp[str] = mini;
    }
    int minCut(string s) {
        map<string, int>mp;
        return find(s, mp);
    }
};

