/*
Given an undirected graph with V vertices labelled from 0 to V-1 and E edges, check whether it contains any cycle or not. Graph is in the form of adjacency list where adj[i] contains all the nodes ith node is having edge with.

Example 1:

Input:  
V = 5, E = 5
adj = {{1}, {0, 2, 4}, {1, 3}, {2, 4}, {1, 3}} 
Output: 1
Explanation: 

1->2->3->4->1 is a cycle.
Example 2:

Input: 
V = 4, E = 2
adj = {{}, {2}, {1, 3}, {2}}
Output: 0
Explanation: 

No cycle in the graph.
 

Your Task:
You don't need to read or print anything. Your task is to complete the function isCycle() which takes V denoting the number of vertices and adjacency list as input parameters and returns a boolean value denoting if the undirected graph contains any cycle or not, return 1 if a cycle is present else return 0.

NOTE: The adjacency list denotes the edges of the graph where edges[i] stores all other vertices to which ith vertex is connected.

 

Expected Time Complexity: O(V + E)
Expected Space Complexity: O(V)


 

Constraints:
1 ≤ V, E ≤ 105

*/

class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    /*
        Basic Intution / Algorith 
            We will be using the dfs based method to detect cyle in the graph in the graph
            Implementation details
            -Along with the visited array in the dfs fucntion we will pass a parent parameter in the dfs fucntion
            -In the dfs fucntion if a particular adj vertix is been marked as visited and it is not the parent vertix then we
                can say that that partuculat graph has cycle
            -Also be sure if the previous recursive call have returned true the we need to check for that condition in the nexted 
            loop as well and return accordengly
            
            
    
    
    */
    
    bool dfs(int source,int parent,vector<bool>& visited,vector<int> adj[])
    {
        visited[source]=true;
        
        for(int i:adj[source]){
            if(visited[i]==false){
                if(dfs(i,source,visited,adj)==true)
                {
                    return true;
                }
                
            }
            else if(i!=parent){
            
                return true;
            }
        }
    
        return false;
    }
    
    
    
    
    
    bool isCycle(int V, vector<int> adj[]) {
    
        vector<bool> visited(V,false);
        for(int i=0;i<V;i++){
            
            
            if(visited[i]==false){
                if(dfs(i,-1,visited,adj)==true){
                     return true;
                }
               
            }
        }
        return false;
        
    }


    
};

