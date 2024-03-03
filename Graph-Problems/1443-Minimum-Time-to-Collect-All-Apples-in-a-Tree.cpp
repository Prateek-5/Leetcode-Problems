/*
Given an undirected tree consisting of n vertices numbered from 0 to n-1, which has some apples in their vertices. You spend 1 second to walk over one edge of the tree. Return the minimum time in seconds you have to spend to collect all apples in the tree, starting at vertex 0 and coming back to this vertex.

The edges of the undirected tree are given in the array edges, where edges[i] = [ai, bi] means that exists an edge connecting the vertices ai and bi. Additionally, there is a boolean array hasApple, where hasApple[i] = true means that vertex i has an apple; otherwise, it does not have any apple.

 

Example 1:


Input: n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple = [false,false,true,false,true,true,false]
Output: 8 
Explanation: The figure above represents the given tree where red vertices have an apple. One optimal path to collect all apples is shown by the green arrows.  
Example 2:


Input: n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple = [false,false,true,false,false,true,false]
Output: 6
Explanation: The figure above represents the given tree where red vertices have an apple. One optimal path to collect all apples is shown by the green arrows.  
Example 3:

Input: n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple = [false,false,false,false,false,false,false]
Output: 0
 

Constraints:

1 <= n <= 105
edges.length == n - 1
edges[i].length == 2
0 <= ai < bi <= n - 1
hasApple.length == n

*/
class Solution {
public:
   /*
        Intution / Basic Algorithm

        -Create a adjList from the given set of edges
        -We will store the time for each node to collect the apple
        -For each node the time required to collect the apple is the sum if the time req by the
            left child and right child
        -For any node we will consider it to have a valid time for apple collection if
            -hasApple[vertex] --> is true
            -If any of it's child has a valid time timeFromChildren
        Since we ar not maintaining a visited array in order the do not end up traversing the same node again and 
            again we pass a addition parent parameter and since it is a tree there whould be no cycle
        -The time varibale will be filled up in a bottom up fasion firstly the leaf node will be return the time of 2
            then every node above it will add a the value returned from the child node haing apple with a extra overhead of 2
            until the root node 
        -Initillly for the root node we need to send the parent parameter as -1
    
    */
    vector<int> memo;
    int dfs(int source,int parent,vector<vector<int>>& adjList,vector<bool>& hasApple)
    {
        int time=0;

        for(int &child:adjList[source])
        {
            if(child==parent)
                continue;

            int timeChildren=dfs(child,source,adjList,hasApple);

            if(timeChildren || hasApple[child])
            {
                time+=(2+timeChildren);
            }

        }
        
        return time;
    }



    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adjList(n);
       

        for(auto &i:edges)
        {
            int u=i[0];
            int v=i[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);

        }
        
        
        return dfs(0,-1,adjList,hasApple);




    }
};
// class Solution {
// public:
    
//     int DFS(unordered_map<int, vector<int>> &adj, int curr, int parent, vector<bool>& hasApple) {
//         int time = 0;
        
//         for(int &child : adj[curr]) {
//             if(child == parent)
//                 continue;
            
//             int time_from_bachha_log = DFS(adj, child, curr, hasApple);
            
//             if(time_from_bachha_log || hasApple[child])
//                 time += 2 + time_from_bachha_log;
            
//         }
        
        
//         return time;
//     }
    
//     int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
//         unordered_map<int, vector<int>> adj;
        
//         for(auto &vec : edges) {
//             int u = vec[0];
//             int v = vec[1];
            
//             adj[u].push_back(v);
//             adj[v].push_back(u);
//         }
        
//         return DFS(adj, 0, -1, hasApple);
//     }
// };