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
	    
	    return parent[u] = find(parent[u], parent);
	}
	void unionOf(int u, int v, int parent[], int rank[]) {
	    
	    if(rank[u] < rank[v]) 
	    parent[u] = parent[v];
	    else if(rank[u] > rank[v])
	    parent[v] = u;
	    else
	    {
	        rank[u] ++;
	        parent[v] = u;
	    }
	}
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
       priority_queue<pair<int, pair< int, int>>, vector<pair<int, pair< int, int>>>, greater<pair<int, pair< int, int>>>>pq;
       
       for(int i = 0; i < V; i++) {
           for(auto it : adj[i]) {
               int wt = it[1];
               int v = it[0];
               pq.push({wt, {i, v}});
           }
       }
       
       int parent[V];
       int rank[V];
       for(int i = 0; i < V; i++) {
           parent[i] = i;
           rank[i] = 0;
       }
       int sum = 0;
       while(!pq.empty()) {
           
           auto it = pq.top();
           pq.pop();
           int wt = it.first;
           int u = it.second.first;
           int v = it.second.second;
           
           int parentu = find(u, parent);
           int parentv = find(v, parent);
           
           if(parentu == parentv)
           continue;
           
           sum += wt;
           unionOf(parentu, parentv, parent, rank);
       }
        
        
        
       return sum;
        
        
        
        
        
        
        
        
        
        
        
        
        
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