/*
There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1 (inclusive). The edges in the graph are represented as a 2D integer array edges, where each edges[i] = [ui, vi] denotes a bi-directional edge between vertex ui and vertex vi. Every vertex pair is connected by at most one edge, and no vertex has an edge to itself.

You want to determine if there is a valid path that exists from vertex source to vertex destination.

Given edges and the integers n, source, and destination, return true if there is a valid path from source to destination, or false otherwise.

 

Example 1:


Input: n = 3, edges = [[0,1],[1,2],[2,0]], source = 0, destination = 2
Output: true
Explanation: There are two paths from vertex 0 to vertex 2:
- 0 → 1 → 2
- 0 → 2
Example 2:


Input: n = 6, edges = [[0,1],[0,2],[3,5],[5,4],[4,3]], source = 0, destination = 5
Output: false
Explanation: There is no path from vertex 0 to vertex 5.
 

Constraints:

1 <= n <= 2 * 105
0 <= edges.length <= 2 * 105
edges[i].length == 2
0 <= ui, vi <= n - 1
ui != vi
0 <= source, destination <= n - 1
There are no duplicate edges.
There are no self edges.

*/

class Solution {
public:
    /*
        Basic Intution / Algorithm
            -The basic idea for the following question is to find out that if we can reach form the source vertix to the destination
            vertix or not 
            -We will create a visited vector and initialize it with false initially
            -After performing the bfs for the source vertix will will again check the the visited position of the 
                source and destination index if they are marked as true then we will return true else false
            -The following problem can be solved using the dfs algorith also but we will tryit using the dfs based algorithm

        Question Specific Steps
            -Since we are given an edges vector we need to create an AdjList using those edges and since it is an bi-directional
                graph we will create accordengly(add 2 records for each input discussed in the code)
            -Once we have created the adjList we call the bfs algo for the source index
            -After we have called the bfs for the source index we need to check the visited status of the destination and return 
            the answer accordengly

            
    */



    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        

        vector<bool> visited(n,false);
        vector<vector<int>> adjList(n);
        /*
            Creation of the Adj List
        */
        for(auto i:edges)
        {
            adjList[i[0]].push_back(i[1]);
            adjList[i[1]].push_back(i[0]);
        }

        /*
            Calling up the bfs algorithm for the source index
        */

        queue<int> q;
        q.push(source);
        visited[source]=true;
        
        while(!q.empty())
        {
            int current=q.front();
            cout<<"visited Index : "<<current<<endl;

            q.pop();
            
            for(int i:adjList[current]){
                if(visited[i]==false)
                {
                    visited[i]=true;
                    q.push(i);
                }
            }
        }
        //returing the status of the visited for the destination index
        return visited[destination];

    }
};