class Solution {
public:
    void findAll(string s, set<string>&st, vector<string>&subAns,  string ans) {
        
        if(s.length() == 0) {
            subAns.push_back(ans.substr(1,ans.length()));
            return;
        }
        
        string temp = "";
        for(int i = 0; i < s.length(); i++) {
            
            temp += s[i];
            if(st.find(temp) != st.end())
            {
                // subAns.push_back(temp);
                findAll(s.substr(i+1, s.length()), st, subAns, ans+" "+temp);
                // subAns.pop_back();
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        set<string>st;
        for(string word : wordDict) 
            st.insert(word);
        vector<string>subAns;
        string ans;
        findAll(s, st, subAns, ans);
        return subAns;
    }
};