/*
Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, Find the number of strongly connected components in the graph.
 

Example 1:

Input:

Output:
3
Explanation:

We can clearly see that there are 3 Strongly
Connected Components in the Graph
Example 2:

Input:

Output:
1
Explanation:
All of the nodes are connected to each other.
So, there's only one SCC.
 

Your Task:
You don't need to read input or print anything. Your task is to complete the function kosaraju() which takes the number of vertices V and adjacency list of the graph of size V as inputs and returns an integer denoting the number of strongly connected components in the given graph.
 

Expected Time Complexity: O(V+E).
Expected Auxiliary Space: O(V+E).
 

Constraints:
1 ≤ V ≤ 5000
0 ≤ E ≤ (V*(V-1))
0 ≤ u, v ≤ V-1
Sum of E over all testcases will not exceed 25*106

*/

class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	
	/*
	    Intution / Basic Algorithm
	  
	  -Calculate the topological sort of the given graph
	  -Once the topological sort is been calculated reverse the edges of the give graph 
	    basically prepare a new adjList for the given graph
	   -Once the topological sort is been prepared and we have the reversed graph apply
	    dfs on the graph in the order as given in the topological sort and keep a count of the
	    number of times the dfs function is been called
	
	
	
	*/
	
	

	    
	    
	    
	    
	    
	
	void dfsFill(int u, vector<vector<int>>& adj, vector<bool> &visited, stack<int>& st) {
	    visited[u] = true;
	    
	    for(int &v : adj[u]) {
	        
	        if(!visited[v]) {
	            dfsFill(v, adj, visited, st);
	        }
	        
	    }
	    /*
	    
	        Caluclate the topological sort usig dfs algorithm
	    
	    */
	    st.push(u);
	}
	
	void dfs(int source,vector<bool>& visited,vector<vector<int>>& adjList)
	{
	    visited[source]=true;
	    for(int i:adjList[source])
	    {
	     
	        if(!visited[i]) 
	            dfs(i,visited,adjList);
	    }
	}
	
	
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        /*
            Calculate the topological sort
        
        */
        // queue<int> topo;
        // topoSort(V,adj,topo);
        
        stack<int> st;
        vector<bool> visited(V, false);
        
        for(int i = 0; i<V; i++) {
            if(!visited[i]) {
                dfsFill(i, adj, visited, st);
            }
        }
        
        /*
            Reverse all the edges of the given graph
        */
        
        vector<vector<int>> adjList(V);
        for(int current=0;current<V;current++)
        {
            for(auto &i:adj[current])
            {
                int u=current;
                int v=i;
                adjList[v].push_back(u);
            }
        }
        /*
            Based on the order in the topological sort call dfs function and keep a track of how many 
            time the dfs function is been called
        
        */
        
        visited=vector<bool>(V,false);
        int count=0;
        
        while(!st.empty())
        {
            int current=st.top();
           
            st.pop();
            if(visited[current]==false)
            {
                
                dfs(current,visited,adjList);
                count++;
            }
        }
        
        return count;
        
        
    }
};