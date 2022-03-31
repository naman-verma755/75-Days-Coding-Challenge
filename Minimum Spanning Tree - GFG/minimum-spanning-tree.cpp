// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	int find(int node, int parent[]) {
	    if(node == parent[node])
	    return node;
	    
	    return parent[node] = find(parent[node], parent);
	}
	void unionOf(int u, int v, int rank[], int parent[]) {
	    if(rank[u] > rank[v]) {
	        parent[v] = u;
	    }
	    else if(rank[u] < rank[v])
	    {
	        parent[u] = v;
	    }
	    else{
	        rank[u]++;
	        parent[v] = u;
	    }
	}
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>pq;
        for(int i = 0; i < V; i++) {
            // cout<<i<<"="<<endl;
            for(auto it : adj[i])
            {
                if(i < it[0]) {
                    pq.push({it[1],{i,it[0]}});
                }
            }
           
        }
        int weightOfTree = 0;
        int parent[V];
        int rank[V];
        for(int i = 0; i < V; i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }
        for(int i =0 ; i < V-1; ) {
            
            auto it = pq.top();
            pq.pop();
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            
            int pt1 = find(u, parent);
            int pt2 = find(v, parent);
            // cout<<u<<" "<<pt1<<v<<" "<<pt2<<endl;
            if(pt1 == pt2)
            continue;
            i++;
            weightOfTree += wt;
            unionOf(pt1, pt2, rank, parent);
        }
        return weightOfTree;;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
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