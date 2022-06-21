class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int size = heights.size();
        stack<int>st;
        int maxi = 0,i;
        for( i  = 0; i < size; i++) {
            
            
            while(!st.empty() && heights[st.top()] > heights[i]) {
                
                int ele = heights[st.top()];
                st.pop();
                
                if(!st.empty())
                    maxi = max(maxi, (i-st.top()-1)*ele);
                else
                    maxi = max(maxi, (i)*ele);
                
            }
            
            st.push(i);
        }
        
        while(!st.empty()) {
                
                int ele = heights[st.top()];
                st.pop();
                
                if(!st.empty())
                    maxi = max(maxi, (i-st.top()-1)*ele);
                else
                    maxi = max(maxi, i*ele);
                
            }
        
        return maxi;
    }
};