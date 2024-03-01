/*
Given an undirected graph with no self loops with V (from 0 to V-1) nodes and E edges, the task is to check if there is any cycle in the undirected graph.

Note: Solve the problem using disjoint set union (DSU).

Example 1:

Input: 

Output: 1
Explanation: There is a cycle between 0->2->4->0
Example 2:

Input: 

Output: 0
Explanation: The graph doesn't contain any cycle
Your Task:
You don't need to read or print anyhting. Your task is to complete the function detectCycle() which takes number of vertices in the graph denoting as V and adjacency list adj and returns 1 if graph contains any cycle otherwise returns 0.

Expected Time Complexity: O(V + E)
Expected Space Complexity: O(V)

Constraints:
2 ≤ V ≤ 104
1 ≤ E ≤ 104

*/

class Solution
{
    public:
    //Function to detect cycle using DSU in an undirected graph.
    
    vector<int> parent;
    vector<int> rank;
    
    /*
        In the below question are are basically implementing the find,union ,path compression and rank in one of it's usecase
        
        Here we maintain a parent and rank vector initially they are been initialized by
            parent ->By the same vertex every element is the parent of itself
            rank-->The initial rank of each vertex is 0
        the findParent is a recursive function which recursively calls the function until it reaches the base case that is
        the parent of the top most element is itself
        
        the rank vector is been used so that we do not end up drawng a skew-symetrical tree that whould incress the time complexity
        
        
    
    
    
    
    
    
    
    */
    int findParent(int a,vector<int>& parent)
    {
        /*
            Base / Terminationg condition for the parent
            
        */
        if(a==parent[a])
        {
            return a;
        }
        
        return parent[a]=findParent(parent[a],parent);
    }
    /*
        In union we basically modify the parent value of the particular vertex and change it to make a union of a single set 
        based on the rank 
    
    
    */
    void unionGraph(int a,int b,vector<int>& parent,vector<int>& rank)
    {
        /*
            Find the parent element of both the verties and check
                --If they are equal then no need to apply union return
                --If not then based on the rank the element which the larger is been made the parent of the other 
                --If the rank are same then we consider any of the element and make it a parent of the other and the
                    element that is been made the parent it's rank is been incremented
        
        */
        
        
        int x=findParent(a,parent);
        int y=findParent(b,parent);
        
        if(x==y)    return;
        if(rank[x] > rank[y])
        {
            parent[y]=x;
        }
        else if(rank[x] < rank[y])
        {
            parent[x]=y;
        }
        else{
            parent[y]=x;
            rank[x]++;
        }
        
    }
    
    
    
    
	int detectCycle(int V, vector<int>adj[])
	{
	    // Code here
	    
	    parent.resize(V);
	    rank.resize(V);
	    for(int i=0;i<V;i++)
	    {
	        parent[i]=i;
	        rank[i]=0;
	    }
	    
	    for(int u=0;u<V;u++)
	    {
	        for(int v:adj[u])
	        {
                /*
                    We have filtered out this condition because it is a uni-directional tree and if we have already made
                    a union of suppose 1--> 2 then there is no need to make a union of 2--> 1 it is the same thing that's 
                    why for other values we are checking their parent and calling their union if required
                
                
                */
                
                if(u>v)     continue;
                /*
                    If two vertxies are in the same union and their is a edge that is connecting them then it means that there is
                    a loop there is present hence we return true for the same
                
                */
	            if(findParent(u,parent)==findParent(v,parent))
	            {
	                return true;
	            }
	            else{
	                unionGraph(u,v,parent,rank);
	            }
	            
	            
	        }
	    }
	   // for(int i=0;i<V;i++)
	   // {
	   //     cout<<parent[i]<<" ";
	   // }
	   // cout<<endl;
	   // for(int j=0;j<V;j++)
	   // {
	   //     cout<<rank[j]<<" ";
	   // }
	    return false;
	    
	    
	    
	    
	    
	}
};