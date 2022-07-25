class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
    
        int m = matrix.size();
        int n= matrix[0].size();
        int dp1[m];
        int dp2[n];
        for(int i = 0; i < m; i++)
           dp1[i] = 1;
        for(int j = 0; j < n; j++)
           dp2[j] = 1;
        for(int i = 0; i < m; i++) 
            for(int j = 0; j < n; j++) 
                if(matrix[i][j] == 0){
                    dp1[i] = 0;
                    dp2[j] = 0;
                }
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(dp1[i] == 0 || dp2[j] == 0)
                    matrix[i][j] = 0;
            }
        }
    }
};