class Solution {
public:
    map<string, int>dp;
    bool find(string word, set<string>&mp) {
        
        if(word.length() == 0)
            return true;
         if(dp.count(word))
             return dp[word];
        string res = "";
        for(int i = 0; i < word.length(); i++) {
            res += word[i];
            if(mp.find(res) != mp.end() && find(word.substr(i+1, word.length()), mp))
                return dp[res] = true;
        }
        
        return dp[res] = false;
        
        
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        
         set<string>mp;
        for(string &word : words) 
            mp.insert(word);
        set<string>ans;
        for(string &word : words) {
            if(word == "")
                continue;
            // if(!mp.count(word)) {
                // cout<<"y";
                string res = "";
                for(int i = 0; i < word.length()-1; i++) {
                    // cout<<word.length()-1<<" ";
                    // cout<<"f";
                    res += word[i];
                    if(mp.find(res) != mp.end() && find(word.substr(i+1, word.length()), mp))
                        ans.insert(word);
                }
            // }
        }
        vector<string>mainAns;
        for(auto it : ans)
            mainAns.push_back(it);
        return mainAns;
    }
};