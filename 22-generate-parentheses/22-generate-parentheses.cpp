class Solution {
public:
    void func(string st, vector<string>&ans, int open, int close, int n) {
        if(open == n && close == n)
        {
            ans.push_back(st);
            return;
        }
        if(open > n || close > n)
            return;
        if(open < n)
        func(st+"(", ans, open+1, close, n);
        if(close < open)
        func(st+")", ans, open, close+1, n);
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        func("", ans, 0, 0, n);
        return ans;
    }
};