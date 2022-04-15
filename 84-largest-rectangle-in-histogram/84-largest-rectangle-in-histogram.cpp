class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        
        stack<int>st;
        int maxi = 0;
        int i;
        for(i = 0; i < heights.size(); i++) {
            
            while(!st.empty() && heights[st.top()] > heights[i]) {
            
                int top = st.top();
                st.pop();
                int  total;
                if(st.empty())
                total = heights[top] * i;
                else
                total = heights[top] * (i-st.top()-1);
                maxi = max(total, maxi);
            }
            st.push(i);
        }
     while(!st.empty()) {
            
                int top = st.top();
                st.pop();
                int  total;
                if(st.empty())
                total = heights[top] * i;
                else
                total = heights[top] * (i-st.top()-1);
         
                maxi = max(maxi, total);
            }
    
    return maxi;
        
    }
};