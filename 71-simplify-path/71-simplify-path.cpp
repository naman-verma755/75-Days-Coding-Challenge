class Solution {
public:
    string simplifyPath(string path) {
        
        stack<string>st;
        for(int i = 0; i < path.length(); ) {
            
            
            if(path[i] == '/') {
                if(st.empty() || st.top() != "/")
                    st.push("/");
                i++;
            } else if(path[i] == '.' || (path[i] >= 'a' && path[i] <= 'z') || (path[i] >= 'A' && path[i] <= 'Z')) {
                
                string dir = "";
                while(i < path.length() && path[i] != '/') {
                    dir += path[i];
                    i++;
                }
                cout<<dir<<" ";
                if(dir == ".")
                    continue;
                if(dir == "..") {
                    if(st.size() > 1) {
                        st.pop();
                        st.pop();
                    }
                }
                else
                    st.push(dir);
            }
            else 
                i++;
            
        }
        if(st.size() > 1 && st.top() == "/") st.pop();
            
        string ans = "";
        while(!st.empty()) {
            ans = st.top()+ans;
            st.pop();
        }
        return ans;
    }
};