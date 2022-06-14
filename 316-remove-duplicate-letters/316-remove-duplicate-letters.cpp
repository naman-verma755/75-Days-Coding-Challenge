class Solution {
public:
    string removeDuplicateLetters(string s) {
        // return "";
        map<char, int>mp;   //storing character and its corresponding last index;
        for(int i = 0; i < s.length(); i++) {
            mp[s[i]] = i;
        }
        stack<int>st;
        set<char>se;
        // cout<<mp['b']<<" ";
        for(int i = 0; i < s.length(); i++) {
            
            if(se.find(s[i]) != se.end())
                continue;
            while(!st.empty() && s[st.top()] > s[i] && mp[s[st.top()]] > i) {
                char ch = s[st.top()];
                se.erase(ch);
                st.pop();
            }
            // if(se.find(s[i]) == se.end()) {
                se.insert(s[i]);
            st.push(i);
            // }
            
            
        }
        string ans = "";
        while(!st.empty()) {
            ans = s[st.top()]+ans; 
            st.pop();
        }
        return ans;
    }
};