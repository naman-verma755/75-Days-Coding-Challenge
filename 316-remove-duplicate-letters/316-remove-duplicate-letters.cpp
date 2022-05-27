class Solution {
public:
    void print(stack<char>st) {
        
        while(!st.empty()) {
            cout<<st.top()<<endl;
            st.pop();
        }
    }
    string removeDuplicateLetters(string s) {
        
        stack<char>stk;
        
        set<char>st;
        int lastOcurrence[27];
        for(int i = 0; i < s.length(); i++) 
            lastOcurrence[s[i]-'a'] = i;
        
        for(int i = 0; i < s.length(); i++) {
            if(st.find(s[i]) != st.end())
                continue;
            while( !stk.empty() && (stk.top() > s[i] && lastOcurrence[stk.top()-'a'] > i)) {
                st.erase(stk.top());
                stk.pop();
            }
                  
            if(st.find(s[i]) == st.end()) {
                st.insert(s[i]);
                  stk.push(s[i]);
            }
        }
                  
        string ans = "";
        while(!stk.empty()) {
            ans = stk.top()+ans;
            stk.pop();
        }
                  return ans;
            
    }
};