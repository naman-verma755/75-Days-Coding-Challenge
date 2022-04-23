// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int>dist(V);
        bool visited[V];
        for(int i = 0; i<V; i++) {
            dist[i] = INT_MAX;
            visited[i] = false;
        }
        dist[S] = 0;
        set<pair<int, int>> st;
        st.insert({0, S});
        // visited[S] = true;
        while(!st.empty()) {
            
            auto it = *(st.begin());
            st.erase(it);
            int u = it.second;
            int wt1 = it.first;
            visited[u] = true;
            
            for(auto it : adj[u]) {
                
                int v = it[0], wt2 = it[1];
                // cout<<wt1+wt2<<endl;
                if( (wt1+wt2) < dist[v]) {
                    // cout<<it[0]<<" ";
                    
                    if(dist[v] != INT_MAX) {
                        st.erase({wt2, v});
                    }
                    dist[v] = (wt1+wt2);
                    st.insert({dist[v], v});
                }
            }
        }
        return dist;
    }
};


// 4 5
// 0 1 9
// 0 2 1
// 0 3 1
// 1 3 3
// 2 3 2
// 0
// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends