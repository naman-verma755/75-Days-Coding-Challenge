class Solution {
public:
    string removeDuplicateLetters(string s) {
        int len = s.length();
        map<int,int>mp;
        for(int i = 0; i < len; i++)
            mp[s[i]] = i;
        stack<int>st;
        set<char>se;
        for(int i = 0; i < len; i++) {
            
            if(se.find(s[i]) != se.end())
                continue;
            while(!st.empty() && s[st.top()] > s[i] && mp[s[st.top()]] > i) {
                se.erase(s[st.top()]);
                st.pop();
            }
            
            if(se.find(s[i]) == se.end()) {
                st.push(i);
                se.insert(s[i]);
            }
            
            
        }
        string ans = "";
        while(!st.empty()) {
            ans += s[st.top()];
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};