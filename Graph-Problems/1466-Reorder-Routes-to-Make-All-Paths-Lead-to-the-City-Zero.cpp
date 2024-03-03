/*
There are n cities numbered from 0 to n - 1 and n - 1 roads such that there is only one way to travel between two different cities (this network form a tree). Last year, The ministry of transport decided to orient the roads in one direction because they are too narrow.

Roads are represented by connections where connections[i] = [ai, bi] represents a road from city ai to city bi.

This year, there will be a big event in the capital (city 0), and many people want to travel to this city.

Your task consists of reorienting some roads such that each city can visit the city 0. Return the minimum number of edges changed.

It's guaranteed that each city can reach city 0 after reorder.

 

Example 1:


Input: n = 6, connections = [[0,1],[1,3],[2,3],[4,0],[4,5]]
Output: 3
Explanation: Change the direction of edges show in red such that each node can reach the node 0 (capital).
Example 2:


Input: n = 5, connections = [[1,0],[1,2],[3,2],[3,4]]
Output: 2
Explanation: Change the direction of edges show in red such that each node can reach the node 0 (capital).
Example 3:

Input: n = 3, connections = [[1,0],[2,0]]
Output: 0
 

Constraints:

2 <= n <= 5 * 104
connections.length == n - 1
connections[i].length == 2
0 <= ai, bi <= n - 1
ai != bi

*/

class Solution {
public:
    /*
        Intution / Basic Algorithm
        -Create a new adjList and make the following graph un-directional
        -All the edges that
            -That are the part of the original connection will have 1 as cost
            -All the new edges that we create will have 0 as cost 
        -Since we need to return the min number of edges that we need to flip to make the following graph point to 0
        -We will call a dfs from the 0th vertex
        -Since in this traversal vwe are moving out from the source vertex to all the far vertext
        -If we are using the original edge to move out from the source we need to file it hence add that cost
            -If we are using the new edge that means the original vertex is already pointing towards the source
                that;s why we have considered it's cost as 0
        -Thourgh the similar approch we will calculate the overall how many number of edges we need to flip
        -And we can return the count as the answer
    
    */

    void dfs(int source,vector<vector<pair<int,int>>>& adjList,int &count,vector<bool>& visited)
    {
        visited[source]=true;
        for(auto &i:adjList[source])
        {   
            /*
                Extracting the destination vertex and the cost
            */
            int v=i.first;
            int cost=i.second;
            if(visited[v]==false)
            {
                count+=cost;
                dfs(v,adjList,count,visited);
            }
        }
    }




    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>> adjList(n);

        for(auto &i:connections)
        {
            int u=i[0];
            int v=i[1];
            /*
                Original with 1 cost
                New with 0 cost
            
            */
            adjList[u].push_back({v,1});
            adjList[v].push_back({u,0});
        }
        vector<bool> visited(n,false);
        int count=0;
        /*
            It's guaranteed that each city can reach city 0 after reorder.
            This point means that the graph is connected so we need to call the dfs only once
        */
        dfs(0,adjList,count,visited);
        return count;


    }
};