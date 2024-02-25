/*
You are given an Undirected Graph having unit weight, Find the shortest path from src to all the vertex and if it is unreachable to reach any vertex, then return -1 for that vertex.

Example:

Input:
n = 9, m= 10
edges=[[0,1],[0,3],[3,4],[4 ,5]
,[5, 6],[1,2],[2,6],[6,7],[7,8],[6,8]] 
src=0
Output:
0 1 2 1 2 3 3 4 4
Your Task:

You don't need to print or input anything. Complete the function shortest path() which takes a 2d vector or array edges representing the edges of undirected graph with unit weight, an integer N as number nodes, an integer M as number of edges and an integer src as the input parameters and returns an integer array or vector, denoting the vector of distance from src to all nodes.

Constraint:
1<=n,m<=100
1<=edges[i][j]<=100

Expected Time Complexity: O(N + E), where N is the number of nodes and E is edges
Expected Space Complexity: O(N)


*/

class Solution {
  public:
  
  /*
        We are given with a edges vector we need to convert the following vector into a AdjList
        After converting it in adjList we need to apply Shortest Path using BFS based traversal
        
        For applying shortest path using bfs traversal we need the following 
            -visited vector
            -distance vector
  
  
  
  */
  
  
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        
        /*
            Covert the edges vector into an AdjList
            
        
        */
        vector<vector<int>> adjList(N);
        for(auto i:edges)
        {
            adjList[i[0]].push_back(i[1]);
            adjList[i[1]].push_back(i[0]);
        }
        
        /*
            the dist vector is used to amintain the distance abd the visited vector is used to maintain the record of
            what all vectors have been visited so that we do no go into an infinite loop
        
        */
        
        vector<int> dist(N,-1);
        queue<int> q;
        vector<bool> visited(N,false);
        
        /*
            Basic initialization we need to maek the distance of the source a 0 and mark it as visited
        
        */
        
        q.push(src);
        dist[src]=0;
        visited[src]=true;
        
        
        /*
            Similar implementaion as that of the bfs traversal just with a small modification to 
            update the distance of the adjecent nodes by 1 as bfs traversal first cover all the nodes that
            are at distance 1
        
        */
        
        while(!q.empty())
        {
            int current=q.front();
            q.pop();
            for(int i:adjList[current])
            {
                if(visited[i]==false)
                {
                    q.push(i);
                    visited[i]=true;
                    dist[i]=1+dist[current];
                    
                }
            }
        }
        
        
        return dist;
        
        
        
        
    }
};
