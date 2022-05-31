class Solution {
public:
    bool func(string s, set<string>&st, map<string, bool>&mp) {
        
        if(s.length() == 0)
            return false;
        if(st.find(s) != st.end())
            return true;
        if(mp.count(s))
            return mp[s];
        string temp = "";
        for(int i = 0; i < s.length(); i++) {
            temp += s[i];
            if(st.find(temp) != st.end() && func(s.substr(i+1, s.length()), st, mp))
               return mp[s] = true;
        }
        return mp[s] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        
        set<string>st;
        map<string, bool>mp;
        for(string word : wordDict) {
            st.insert(word);
        }
       return func(s, st, mp);
    }
};