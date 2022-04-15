class Solution {
public:
    void findAllCombinations(int index, string digits, string res, map<char, string>&mp, vector<string>&ans) {
        
        if(index >= digits.length()) {
            if(res != "")
            ans.push_back(res);
            return;
        }
         // cout<<digits[index]<<" ";
         string str = mp[digits[index]];
        // cout<<str<<" ";
        
        for(int i = 0; i < str.length(); i++) {
            findAllCombinations(index+1, digits, res+str[i], mp, ans);
        }
    }
    vector<string> letterCombinations(string digits) {
        map<char, string>mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        vector<string> ans;
        
        findAllCombinations(0, digits, "", mp, ans);
            
        return ans;
        
    }
};