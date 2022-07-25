class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        int size = temperatures.size();
        stack<int>st;
        vector<int>ans(size, 0);
        for(int i = 0; i < size; i++) {
            
            while(!st.empty() && temperatures[st.top()] < temperatures[i]) {
                ans[st.top()] = i-st.top();
                st.pop();
            }
            
            st.push(i);
        }
        return ans;
    }
};