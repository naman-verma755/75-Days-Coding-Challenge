class Solution {
public:
   
    int largestRectangleArea(vector<int>& heights) {
        int size = heights.size();
        int maxi = INT_MIN;
        stack<int>st;
        int i;
        for( i = 0; i < size; i++) {
        
            while(!st.empty() && heights[st.top()] > heights[i]) {
                int ele = heights[st.top()];
                st.pop();
                
                if(!st.empty())
                    maxi = max(maxi, (ele*(i-st.top()-1)));
                else
                    maxi = max(maxi, (ele*i));
               
            }
            st.push(i);
        }
   
         while(!st.empty() ) {
              int ele = heights[st.top()];
                st.pop();
                
                if(!st.empty())
                    maxi = max(maxi, (ele*(i-st.top()-1)));
                else
                    maxi = max(maxi, (ele*i));
            }
        return maxi;
    }
};