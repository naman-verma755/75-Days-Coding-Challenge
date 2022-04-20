class Solution {
public:
    string simplifyPath(string path) {
        int pathLength = path.length();
        stack<string>st;
    
        int i = 0;
        while(i < pathLength) {
         
            if(path[i] == '/') {
                if(st.empty() || st.top() != "/") {
                    st.push("/");
                }
                i++;
                continue;
            }
       
            string res = "";
            while(i < pathLength && path[i] != '/') {
                res += path[i];
                i++;
            }
            
            if(res == "..") {
                if(st.size() > 1) {
                    st.pop();
                    st.pop();
                }
            }
            else if(res == ".")
                continue;
            else
                st.push(res);
        }
        
        string ans = "";
        if(st.size() > 1 && st.top() == "/")
            st.pop();
        while(!st.empty()) {
            ans = st.top()+ans;
            st.pop();
        }
        return ans;
    }
};