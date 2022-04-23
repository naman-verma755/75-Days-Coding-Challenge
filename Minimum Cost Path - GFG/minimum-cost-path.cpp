// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        // Code here
        int N = grid.size();
        vector<vector<int>>dist(N, vector<int>(N, INT_MAX));
        dist[0][0] = grid[0][0];
        
        set<pair<int, pair<int, int>>>st;
        int dir1[] = {-1, 0, 1, 0};
        int dir2[] = {0, 1, 0, -1};
        st.insert({grid[0][0], {0, 0}});
        while(!st.empty()) {
            
            auto it = *(st.begin());
            st.erase(it);
            int wt1 = it.first;
            int u1 = it.second.first;
            int u2 = it.second.second;
            
            for(int i = 0; i < 4; i++) {
                int x = u1+dir1[i], y = u2+dir2[i];
                if(x >= 0 && y >= 0 && x < N && y < N) {
                    int wt2 = grid[x][y];
                    if((wt1+wt2) < dist[x][y]) {
                        if(dist[x][y] != INT_MAX) {
                            st.erase({dist[x][y], {x,y}});
                        }
                        dist[x][y] = (wt1+wt2);
                        st.insert({dist[x][y], {x,y}});
                    }
                }
            }
            
            
        }
        // for(int i = 0; i < N; i++) {
        //     for(int j = 0; j < N; j++)
        //     cout<<dist[i][j]<<" ";
        //     cout<<endl;
        // }
        // cout<<endl;
        
        return dist[N-1][N-1];
        
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
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends