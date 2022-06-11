// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	int find(int u, int parent[]) {
	    if(u == parent[u])
	    return u;
	    
	    return parent[u] = find(parent[u], parent); // path compression;
	}
	
	void unionOf(int u, int v, int rank[], int parent[]) {
	    
	    if(rank[u] < rank[v]) {
	        parent[u] = v;
	    }
	    else if(rank[v] < rank[u]) {
	        parent[v] = u;
	    }
	    else {
	        rank[u]++;
	        parent[v] = u;
	    }
	}
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        int parent[V];
        int rank[V];
        for(int i = 0; i < V; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
        vector<vector<int>>v;
        
        for(int i = 0; i < V; i++) {
            for(vector<int>&edge : adj[i]) 
            v.push_back(vector<int>()= {edge[1], i, edge[0]});
        }
        
        sort(v.begin(), v.end());
        int count = 0, cost = 0;
        int i = 0;
        // cout<<v[0][0]<<v[0][1]<<v[0][2];
        while(count < V-1) {
            // cout<<v[i][1]<<" "<<v[i][2]<<endl;
            int wt = v[i][0];
            int u = v[i][1];
            int e = v[i][2];
            
            int parentU = find(u, parent);
            int parentV = find(e, parent);
            
            if(parentU == parentV) {
                i++;
                continue;
            }
            
            unionOf(parentU, parentV, rank, parent);
            
            count++;
            cost += wt;
            i++;
            
        }
        return cost;
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
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends