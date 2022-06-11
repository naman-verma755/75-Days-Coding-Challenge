// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    bool dfs(int row, int col, vector<vector<int>>& grid, vector<vector<bool>>&visited, int dist) {
        int n = grid.size();
        
        if(row < 0 || row == n || col < 0 || col == n)
        return false;
        
        
        if(grid[row][col] == 0 || visited[row][col])
        return false;
        
        if(grid[row][col] == dist)
        return true;
        visited[row][col] = true;
        
        bool res1 = dfs(row+1, col, grid, visited, dist);
        bool res2 = dfs(row-1, col, grid, visited, dist);
        bool res3 = dfs(row, col+1, grid, visited, dist);
        bool res4 = dfs(row, col-1, grid, visited, dist);
        return (res1 || res2 || res3 || res4);
    }
    bool is_Possible(vector<vector<int>>& grid) 
    {
        //code here
        int n = grid.size();
        vector<vector<bool>>visited(n, vector<bool>(n, false));
        
        int col,row, dist;
        bool flag = false;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n ; j++) {
                if(grid[i][j] == 1) {
                    dist = 2;
                    row = i;
                    col = j;
                    flag = true;
                    break;
                }
                else if(grid[i][j] == 2) {
                    dist = 1;
                    row = i;
                    col = j;
                    flag = true;
                    break;
                }
            }
            if(flag )
            break;
        }
        return dfs(row, col, grid, visited, dist);
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}  // } Driver Code Ends