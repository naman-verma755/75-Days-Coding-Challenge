class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        
         sort(intervals.begin(), intervals.end()); 
        // int a = intervals[0][0];
        // int b = intervals[0][1];
        int a= -1, b= -1;
        vector<vector<int>>ans;
        for(int i = 0; i < intervals.size(); i++) {
            
            if(a == -1 && b == -1) {
                a = intervals[i][0];
                b = intervals[i][1];
            }
            
            if(b >= intervals[i][0]) {
                a = min(intervals[i][0], a);
                b = max(intervals[i][1], b);
            }
            else
            {
                ans.push_back(vector<int>()= {a,b});
                a = intervals[i][0];
                b = intervals[i][1];
            }
            
        }
        ans.push_back(vector<int>()= {a,b});
        
        return ans;
        
    }
};