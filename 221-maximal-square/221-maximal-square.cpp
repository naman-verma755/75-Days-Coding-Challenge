class Solution {
public:
    
    int findSquare(vector<int>&heights) {
        
           stack<int>st;
        int maxi = 0;
        // for(int i = 0; i < heights.size(); i++)
        //     cout<<heights[i]<<" ";
        int i;
        for(i = 0; i < heights.size(); i++) {
            
            while(!st.empty() && heights[st.top()] > heights[i]) {
            
                int top = st.top();
                // cout<<top<<" ";
                st.pop();
                int  mini = -1;
                if(!st.empty())
                mini = min(heights[top], (i-st.top()-1));
                else
                    mini = min(heights[top], i-top);
                // cout<<mini<<" ";
                // total = heights[top] * (i-st.top()-1);
                maxi = max((mini*mini), maxi);
            }
            st.push(i);
        }
        
     while(!st.empty()) {
            
                int top = st.top();
                st.pop();
               int  mini;
                if(!st.empty())
                mini = min(heights[top], (i-st.top()-1));
                else
                     mini = min(heights[top], i-top);
                // cout<<mini<<" ";
                // total = heights[top] * (i-st.top()-1);
                maxi = max((mini*mini), maxi);
            }
    // cout<<endl;
    return maxi;
        
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        
        vector<int>heights(matrix[0].size(), 0);
        int maximalSquare_ = 0;
        for(int i = 0; i < matrix.size();i++) {
            
            for(int j = 0; j < matrix[0].size(); j++) {
                if(matrix[i][j] == '1')
                    heights[j] += 1;
                else
                    heights[j] = 0;
            }
            int total = findSquare(heights);
            // cout<<total<<" ";
            maximalSquare_ = max(maximalSquare_, total);
            
        }
      return maximalSquare_;
        
    }
                           
                           
                           
                           
                           
                           
                           
                           
                           
                           
};