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
        
        vector<int>dist(V, INT_MAX);
        
        
        
        set<pair<int, int>>st;  
        dist[S] = 0;
        st.insert({0, S});
        
        while(!st.empty()) {
            
            pair<int, int>it = *(st.begin());
            st.erase(it);
            
            int u = it.second;
            int wt1 = it.first;
            
            for(vector<int>&edge : adj[u]) {
                int v = edge[0];
                int sum = wt1+edge[1];
                if(sum < dist[v]) {
                    if(dist[v] != INT_MAX) 
                    st.erase({dist[v], v});
                    
                    dist[v] = sum;
                    st.insert({sum, v});
                }
            }
        }
        return dist;
    }
};


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