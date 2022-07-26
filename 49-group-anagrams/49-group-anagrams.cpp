class Solution {
public:
    string getNum(string st) {
        int sum = 0;
        int freq[26] = {};
        for(int i = 0; i < st.length(); i++) 
            freq[st[i]-'a']++;
        string str = "";
        for(int i = 0; i < 26; i++) 
        {
            if(freq[i] > 0) 
                str += (char)('a'+i)+to_string(freq[i]);
        }
        return str;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        map<string, vector<string>>mp;
        
        for(string str : strs) {
            
            string hash = getNum(str);
            // cout<<str<<" = "<<hash<<endl;
            
            if(!mp.count(hash))
                mp[hash] = vector<string>();
            
            mp[hash].push_back(str);
        }
        
        vector<vector<string>>ans;
        for(auto it : mp) {
            ans.push_back(it.second);
        }
        return ans;
    }
};