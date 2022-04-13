class Solution {
public:
    string multiply(string num, string str) {
        // cout<<num<<endl;
        int n = 0, j =0;
        while(j < num.length()) {
            n = 10*n+(num[j]-'0');
            j++;
        }
        // cout<<n<<" ";
        int i = 0;
        string re = "";
        while(i < n) {
            re += str;
            i++;
            
        }
        return re;
    }
    
    string decodeString(string s) {
        stack<string>st;
        for(int i = 0; i < s.length(); ) {
            
            string temp = "";
            while(i < s.length() && s[i] >= 'a' && s[i] <='z') {
                temp += s[i];
                i++;
            }
            if(temp != "")
                st.push(temp);
            if(i >= s.length())
                break;
            if(s[i] == ']') {
                string r = "";
                while(!st.empty() && st.top() != "[") {
                    r = st.top()+r;
                    st.pop();
                    
                }
               
                st.pop();
                string num = st.top();
                st.pop();
                string str = multiply(num, r);
                st.push(str);
                
            }
            else if(s[i] >= '1' && s[i] <='9') {
                string r = "";
                while(i < s.length() && s[i] >= '0' && s[i] <= '9') {
                    r += s[i];
                    i++;
                }
                st.push(r);
                continue;
            }
            else {
                string temp = "";
                temp +=s[i];
                st.push(temp);
            }
           
            i++;
        }
string ans ="";
        while(!st.empty())
        {
            ans = st.top()+ans;
            st.pop();
        }
        return ans;
    }
};