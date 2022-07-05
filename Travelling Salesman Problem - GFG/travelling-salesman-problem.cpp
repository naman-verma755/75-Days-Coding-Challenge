// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
public:
void dfs(int index, vector<vector<int>>&mat, bool visited[], int cost, int &mini,int n) {
    
    visited[index] = true;
    
    bool flag = false;
    for(int i = 1; i < n; i++ ) {
        
        if(!visited[i] && i != index) {
            flag = true;
            dfs(i, mat, visited, cost+mat[index][i], mini, n);
        }
    }
    
    if(!flag)
        mini = min(mini, cost+mat[index][0]);
    visited[index] = false;
    
}
int total_cost(vector<vector<int>>cost){
    // Code here
    int n = cost.size();
    bool visited[n];
        for(int i = 0; i < n; i++)
            visited[i] = false;
        int mini = INT_MAX;
        dfs(0, cost, visited, 0, mini, n);
        return mini;
}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>cost(n, vector<int>(n, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)cin >> cost[i][j];
		Solution obj;
		int ans = obj.total_cost(cost);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends