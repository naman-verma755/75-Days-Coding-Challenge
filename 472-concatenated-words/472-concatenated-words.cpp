class Solution {
public:
    map<string, int>dp;
    bool find(string word, map<string, int>&mp) {
        
        if(word.length() == 0)
            return true;
        if(dp.count(word))
            return dp[word];
        string res = "";
        for(int i = 0; i < word.length(); i++) {
            res += word[i];
            if(mp.count(res) && find(word.substr(i+1, word.length()), mp))
                return dp[res] = true;
        }
        
        return dp[res] = false;
        
        
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        
         map<string, int>mp;
        set<string>subAns;
        for(string &word : words) 
            mp[word] = 1;
        vector<string>ans;
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
                    if(mp.count(res) && find(word.substr(i+1, word.length()), mp))
                        subAns.insert(word);
                }
            // }
        }
        for(auto word : subAns)
            ans.push_back(word);
        return ans;
    }
};