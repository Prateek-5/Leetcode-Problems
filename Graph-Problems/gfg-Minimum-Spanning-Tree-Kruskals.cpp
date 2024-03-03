/*
Given a weighted, undirected and connected graph of V vertices and E edges. The task is to find the sum of weights of the edges of the Minimum Spanning Tree. Given adjacency list adj as input parameters . Here adj[i] contains vectors of size 2, where the first integer in that vector denotes the end of the edge and the second integer denotes the edge weight.

 

Example 1:

Input:
3 3
0 1 5
1 2 3
0 2 1

Output:
4
Explanation:

The Spanning Tree resulting in a weight
of 4 is shown above.
Example 2:

Input:
2 1
0 1 5

Output:
5
Explanation:
Only one Spanning Tree is possible
which has a weight of 5.
 

Your task:
Since this is a functional problem you don't have to worry about input, you just have to complete the function spanningTree() which takes a number of vertices V and an adjacency list adj as input parameters and returns an integer denoting the sum of weights of the edges of the Minimum Spanning Tree. Here adj[i] contains vectors of size 2, where the first integer in that vector denotes the end of the edge and the second integer denotes the edge weight.

Expected Time Complexity: O(ElogV).
Expected Auxiliary Space: O(V2).
 

Constraints:
2 ≤ V ≤ 1000
V-1 ≤ E ≤ (V*(V-1))/2
1 ≤ w ≤ 1000
The graph is connected and doesn't contain self-loops & multiple edges.

*/
class Solution
{   
    
    /*
        Kruskal's Algorithm implementation
        -Write the logic for union , find to connect components
        -Sort the connection in accending order of their weights / edges 
        -Create a vector with of vector where the schema is {u,v,weight}
        -Iterate throught the adj / connection vector and inculde only those edges that connect 2 un-connected components 
        -Store the sum in a variable of all those components which are been included
    
    */
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	
	
	
	
	
	int findNode(int a,vector<int>& parent)
	{
	    
	    if(a==parent[a])
	    {
	        return a;
	    }
	    
	    return parent[a]=findNode(parent[a],parent);
	}
	
	
	void unionNode(int a,int b,vector<int>& parent,vector<int>& rank)
	{
	    int x=parent[a];
	    int y=parent[b];
	    
	    if(x==y)    return;
	    if(rank[x] > rank [y])
	    {
	        parent[y]=x;
	    }
	    else if(rank[y] > rank[x])
	    {
	        parent[x]=y;
	    }
	    else{
	        parent[y]=x;
	        rank[x]++;
	    }
	    
	}
	
	static bool myComp(vector<int>& a,vector<int>& b)
	{
	    return a[2] < b[2];
	}
	
	
	
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        
        vector<int> parent(V);
        vector<int> rank(V,0);
        for(int i=0;i<V;i++)
        {
            parent[i]=i;
        }
        
        vector<vector<int>> vec;
        for(int i = 0; i<V; i++) {
            
            for(auto &temp : adj[i]) {
                
                int u = i;
                int v = temp[0];
                int d = temp[1];

                vec.push_back({u, v, d});
                
            }
            
        }
        sort(begin(vec),end(vec),myComp);
        int sum=0;
        for(auto i:vec)
        {
            int u=i[0];
            int v=i[1];
            int weight=i[2];
            
            if(findNode(u,parent)!=findNode(v,parent))
            {
                
                unionNode(u,v,parent,rank);
                sum+=weight;
            }
            
            
        }
        return sum;
        
        
    }
};