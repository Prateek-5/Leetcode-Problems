/*
You are given a directed graph of n nodes numbered from 0 to n - 1, where each node has at most one outgoing edge.

The graph is represented with a given 0-indexed array edges of size n, indicating that there is a directed edge from node i to node edges[i]. If there is no outgoing edge from i, then edges[i] == -1.

You are also given two integers node1 and node2.

Return the index of the node that can be reached from both node1 and node2, such that the maximum between the distance from node1 to that node, and from node2 to that node is minimized. If there are multiple answers, return the node with the smallest index, and if no possible answer exists, return -1.

Note that edges may contain cycles.

 

Example 1:


Input: edges = [2,2,3,-1], node1 = 0, node2 = 1
Output: 2
Explanation: The distance from node 0 to node 2 is 1, and the distance from node 1 to node 2 is 1.
The maximum of those two distances is 1. It can be proven that we cannot get a node with a smaller maximum distance than 1, so we return node 2.
Example 2:


Input: edges = [1,2,-1], node1 = 0, node2 = 2
Output: 2
Explanation: The distance from node 0 to node 2 is 2, and the distance from node 2 to itself is 0.
The maximum of those two distances is 2. It can be proven that we cannot get a node with a smaller maximum distance than 2, so we return node 2.
 

Constraints:

n == edges.length
2 <= n <= 105
-1 <= edges[i] < n
edges[i] != i
0 <= node1, node2 < n



*/
class Solution {
public:

    /*
        Intution / Basic Algorithm

        -Calculate the distance all the nodes formt eh two nodes give
            -Distance of node1 from rest dist1
            -Distance of node2 from rest dist2
        -Once we have calculated the distance of all the nodes from node1 and node2
            -We need to calculate the max between the dist1 and dist2 from every index
            -Once we have the max between dist1 adn dist2 we need to calculate the min distance and store it's index
        -Once we have iterated throught the whole array we need to return the index of the min diststance out of the max distance
    
    
    
    
    
    
    */



    vector<int> bfs(int source,vector<int>& edges)
    {
        int n=edges.size();
        vector<int> dist(n,INT_MAX);
        queue<int> q;
        q.push(source);

        vector<bool> visited(n,false);
        dist[source]=0;
        visited[source]=true;
        
        while(!q.empty())
        {
            int current=q.front();
            
            q.pop();
            int v=edges[current];

            if(v!=-1 && !visited[v])
            {
                visited[v]=true;
                dist[v]=1+dist[current];
                q.push(v);
            }

        }

        return dist;





    }





    int closestMeetingNode(vector<int>& edges, int node1, int node2) {


        vector<int> dist1=bfs(node1,edges);
        vector<int> dist2=bfs(node2,edges);


        // for(int i:dist1)
        // {
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        // for(int i:dist2)
        // {
        //     cout<<i<<" ";
        // }
        
        int n=edges.size();
        
        int minDistNode    = -1;
        int minDistTillNow = INT_MAX;
        for (int i = 0; i < n; i++) {
            /*
                Return the index of the node that can be reached from both node1 and node2,
                such that the maximum between the distance from node1 to that node, and from
                node2 to that node is minimized. 
            
                Out of the maximum value between dist1 and dist2 compute the min value
                Once we have found out the min value store the index

                Ex: dist1={0,INT_MAX,1,2}
                    dist2={INT_MAX,0,1,2}
                the max value out of the 2 vectors
                        INT_MAX,INT_MAX,1,2
                    Out of these max value we need to compute the min value and store it's index
            
            */
            int maxD = max(dist1[i], dist2[i]);
            
            if (minDistTillNow > maxD) {
                minDistNode = i;
                minDistTillNow = maxD;
            }
        }

        return minDistNode;
    

    }
};