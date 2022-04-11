class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>ans(n,vector<int>(m));
        int size = (n*m);
        // cout<<size;
        if(k >= size)
            k%=size;
if(k == 0)
    return grid;
        // int prev = grid[(size-k)%m][(size-k)%m];
        
        int i = n*m-k;
        int j = 0;
        while(j < n*m) {
            int r = i/m;
            int c= i%m;
            // cout<<grid[r][c]<<" ";
            int r2 = j/m;
            int c2 = j%m;
            ans[r2][c2] = grid[r][c];
            j++;
            i++;
            if(i >= size)
            i %= size;
            //  if(j>= size)
            // j%= size;
        }
        return ans;
        
    }
};