class Solution {
public:
    void findWords(string s, map<string, int>&words) {
        
        int i = 0;
        while(i < s.length()) {
            
            if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >='A' && s[i] <= 'Z')) {
                string res = "";
                while(i < s.length() && ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >='A' && s[i] <= 'Z'))) {
                    // cout<<i<<
                    if( s[i] >='A' && s[i] <= 'Z')
                    res += (s[i]+32);
                    else
                       res += s[i];
                    
                    i++;
                }
                words[res] ++;
                
                
            }
            else
                i++;
        }
    }
    string mostCommonWord(string paragraph, vector<string>& banned) {
        
        map<string, int>bannedWords;
        for(auto it : banned)
            bannedWords[it] = 1;
        
        map<string, int>words;
        findWords(paragraph, words);
        int maxi = -1;
        string ans="";
        for(auto it : words) {
            // cout<<it.first<<" "<<it.second<<endl;
            if(!bannedWords.count(it.first)) {
                if(it.second > maxi) {
                    maxi = it.second;
                    ans = it.first;
                }
            }
        }
        return ans;
    }
};