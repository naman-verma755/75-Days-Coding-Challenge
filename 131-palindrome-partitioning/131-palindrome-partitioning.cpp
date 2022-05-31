class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.length()-1;
        while(i < j) {
            if(s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    void func(int index, string s, vector<string>subAns, vector<vector<string>>&ans) {
        
        if(index == s.length()) {
            ans.push_back(subAns);
            return;
        }
        string st = "";
        for(int i = index; i < s.length(); i++) {
            st += s[i];
            if(isPalindrome(st)) {
                subAns.push_back(st);
                func(i+1, s, subAns, ans);
                subAns.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>subAns;
        func(0, s, subAns, ans);
        return ans;
    }
};