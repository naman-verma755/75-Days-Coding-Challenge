class Solution {
public:
    string func(string st, string re) {
        int k = stoi(st);
        // int r = stoi(re);
        string te = "";
        while(k > 0) {
            te = te+re;
            k--;
        }
        return te;
        
    }
    string decodeString(string s) {
        
        int i = 0;
        int len = s.length();
        stack<string>st;
        while( i < len) {
            // cout<<i<<" ";
            if(s[i] == ']') {
                string ans = "";
                while(!st.empty() && st.top() != "[") {
                    ans = st.top()+ans;
                    st.pop();
                }
                st.pop();
                string res = func(st.top(), ans);
                // cout<<res<<" ";
                st.pop();
                st.push(res);
                i++;
                
                
            }
            else if(s[i] == '[') {
                st.push("[");
                i++;
                
            }
            else if(s[i] >= '0' && s[i] <= '9'){
                string er = "";
                while(i < len && (s[i] >= '0' && s[i] <= '9')) {
                    er = er + s[i];
                    i++;
                }
                st.push(er);
            }
            else if(s[i] >= 'a' && s[i] <= 'z') {
                string er = "";
                while(i < len && (s[i] >= 'a' && s[i] <= 'z')) {
                    er = er + s[i];
                    i++;
                }
                st.push(er);
            }
        }
        string ans = "";
        while(!st.empty()) {
            ans = st.top()+ans;
            st.pop();
        }
        return ans;
    }
};