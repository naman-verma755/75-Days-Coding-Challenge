class Solution {
public:
    string removeKdigits(string num, int k) {

        stack<char>st;
        for(int i = 0; i < num.length(); i++) {
            
            while(!st.empty() && st.top() > num[i] && k > 0) {
                st.pop();
                k--;
            }
            
            st.push(num[i]);
        }
        
        
        
        if(st.empty())
            return "0";
        // while(!st.empty() && st.top() == '0')
        //     st.pop();
        
        string ans = "";
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
         reverse(ans.begin(), ans.end());
        while( k>0 )
            ans.pop_back(),k--;
        int i = 0;
        while(i < ans.length() && ans[i] == '0')
            i++;
        ans = ans.substr(i, ans.length());
       
        if(ans == "")
            return "0";
        
        return ans;
    }
};