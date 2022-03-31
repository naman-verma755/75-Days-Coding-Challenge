class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        int maxi = INT_MIN;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                
                if(grid[i][j] == 1) {
                    
                    queue<pair<int,int>>qu;
                    qu.push({i,j});
                    grid[i][j] = 2;
                    int dir1[] = {-1, 0, 1, 0};
                    int dir2[] = {0, 1, 0, -1};
                    int area = 0;
                    while(!qu.empty()) {
                        int size = qu.size();
                        // cout<<size<<" ";
                        area += size;
                        while(size > 0) {
                            pair<int,int>it = qu.front();
                            qu.pop();
                            int u = it.first;
                            int v = it.second;
                           
                            for(int k = 0; k < 4; k++) 
                            {
                                int x = u+dir1[k];
                                int y = v+dir2[k];
                                if(x >= 0 && x < n && y >=0 && y < m) {
                                    if(grid[x][y] == 1) {
                                        qu.push({x,y});
                                        grid[x][y] = 2;
                                    }
                                }
                            }
                            size--;
                        }
                        
                    }
                    // cout<<area<<" ";
                    // cout<<endl;
                    maxi = max(maxi, area);
                }
                
                
            }
        }
        if(maxi == INT_MIN)
            return 0;
        return maxi;
        
    }
};