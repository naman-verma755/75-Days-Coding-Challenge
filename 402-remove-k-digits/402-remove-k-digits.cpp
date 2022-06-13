class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans="";
        for(char &c:num)
        {
            while(ans.size() && ans.back()>c &&k)
            {
                ans.pop_back();
                k--;
            }
            if(ans.size() || c!='0')ans.push_back(c);
        }
        while(ans.size()&&k--)          // <-------this look is to make sure we fulfil the deletion condition
        {
            ans.pop_back();
        }
        return (ans=="")?"0":ans;
//         stack<char>st;
        
//         for(char ch: num) {
            
//              while(!st.empty() && ch < st.top() && k > 0) 
//                  st.pop(),k--;
            
//             if(ch == '0' && st.size() == 0)
//                 continue;
//             st.push(ch);
//         }
// //         // cout<<st.top();
        
//         string ans = "";
//         while(!st.empty()) {
//             ans = st.top()+ans;
//             st.pop();
//         }
//         // ans = ans.substr(0, ans.length()-k);
        
//         while(ans.size()&&k--)           
//         {
//             ans.pop_back();
//         }
//         if(ans == "")
//             return "0";
//         return ans;
    
    }
};