class Solution {
public:
    string simplifyPath(string path) {
        
        int len = path.length();
        stack<string>st;
        int i = 0;
        
        while(i < len) {
            
          
            if( path[i] == '/' ) {
                
                if(st.empty() || st.top() != "/")
                {
                    st.push("/");
                }
                i++;
                continue;
                
            }
           
                string s = "";
                while(i < path.length() && path[i] != '/') {
                    s += path[i];
                    i++;
                }
            cout<<s<<" ";
                if(s == ".")
                    continue;
                if(s == ".." )
                {
                    if(st.size() > 1) {
                        st.pop();
                        st.pop();
                    }
                }
                else {
                    st.push(s);
                }
                
            
            
        }
        if(st.size() != 1 && st.top() == "/")
            st.pop();
        string ansPath = "";
        while(!st.empty()  ) {
            ansPath = st.top() + ansPath;
            st.pop();
        }
        return ansPath;
    }
};