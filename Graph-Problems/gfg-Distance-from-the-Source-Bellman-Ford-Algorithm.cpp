/*
Given a weighted and directed graph of V vertices and E edges, Find the shortest distance of all the vertex's from the source vertex S. If a vertices can't be reach from the S then mark the distance as 10^8. Note: If the Graph contains a negative cycle then return an array consisting of only -1.

Example 1:

Input:

E = [[0,1,9]]
S = 0
Output:
0 9
Explanation:
Shortest distance of all nodes from
source is printed.
Example 2:

Input:

E = [[0,1,5],[1,0,3],[1,2,-1],[2,0,1]]
S = 2
Output:
1 6 0
Explanation:
For nodes 2 to 0, we can follow the path-
2-0. This has a distance of 1.
For nodes 2 to 1, we cam follow the path-
2-0-1, which has a distance of 1+5 = 6,
 

Your Task:
You don't need to read input or print anything. Your task is to complete the function bellman_ford( ) which takes a number of vertices V and an E-sized list of lists of three integers where the three integers are u,v, and w; denoting there's an edge from u to v, which has a weight of w and source node S as input parameters and returns a list of integers where the ith integer denotes the distance of an ith node from the source node.

If some node isn't possible to visit, then its distance should be 100000000(1e8). Also, If the Graph contains a negative cycle then return an array consisting of a single -1.

 

Expected Time Complexity: O(V*E).
Expected Auxiliary Space: O(V).

 

Constraints:
1 ≤ V ≤ 500
1 ≤ E ≤ V*(V-1)
-1000 ≤ adj[i][j] ≤ 1000
0 ≤ S < V


*/

class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    
    /*
        Dijkstra Algorith has some drawback that is it cannot be used for -ve edges as if there is a negative cycle then
        the distance that it will compute will be inaccurate 
        
        For the same we have Bellman Ford algorithm Some important points for Bellman ford
            -It always works of directed grap if undirected is given the we need to convert it into directed
            -We required the vector of edges int the formate of <u,v,cost>
            -We need to itereate throught these edges in the same order V-1 time 
            -As per Bellman Ford algo we will get our answer in V-1 iterations only the min possible distance if there is not 
                negative cycyle in the graph
            -If there is a negative cycyle in the graph then after V-1 iteration on Vth iteration we will get a new smaller distance
            that is an indication of a newgative cycyle hence we have to return from that point indicating that there is a 
            negative cycle in the graph as we have dobe below
            -The replaxation code is same is dijkstra which is 
                if(dist[v] > dist[u] + cost)
                {
                    if(j==V-1)      return {-1};
                    dist[v]=dist[u] + cost;
                }
            Keep in mind like in topological sort we are computing the distance based on the dist[u] we need to make sure that 
            we have a non infinite value in out dist[u] before making the update hence we need to write a condition for the same
            
            In the below loop we have intentionally run the loop V time rather than V-1th time because if there is some relaxation in 
            the distance we can detect the loop and return accordengly
            
            
    
    */
    
    
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        // Code here
        
        vector<int> dist(V,1e8);
        dist[S]=0;
        int j;
        for(j=0;j<V;j++)
        {
            for(auto i:edges)
            {
                int u=i[0];
                int v=i[1];
                int cost=i[2];
                
                if(dist[u]==1e8)    continue;
                
                if(dist[v] > dist[u] + cost)
                {
                    if(j==V-1)      return {-1};
                    dist[v]=dist[u] + cost;
                }
                
                
            }
        }
        
        
        
        return dist;
        
        
        
    }
};
