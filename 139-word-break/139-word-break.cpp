class Solution {
public:
    
    bool func(string s, set<string>&st, map<string, int>&mp) {
        
        if(s.length() == 0)
            return true;
        
        if(mp.count(s))
            return mp[s];
        string re = "";
        
        for(int i = 0; i < s.length(); i++) {
            re += s[i];
            if(st.find(re) != st.end()) {
                if(func(s.substr(i+1), st, mp))
                    return mp[s] = true;
            }
        }
        return mp[s] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        
        set<string>st;
        map<string, int>mp;
        for(string word : wordDict)
            st.insert(word);
        
        return func(s, st, mp);
    }
};