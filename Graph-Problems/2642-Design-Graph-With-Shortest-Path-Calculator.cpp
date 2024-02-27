/*
There is a directed weighted graph that consists of n nodes numbered from 0 to n - 1. The edges of the graph are initially represented by the given array edges where edges[i] = [fromi, toi, edgeCosti] meaning that there is an edge from fromi to toi with the cost edgeCosti.

Implement the Graph class:

Graph(int n, int[][] edges) initializes the object with n nodes and the given edges.
addEdge(int[] edge) adds an edge to the list of edges where edge = [from, to, edgeCost]. It is guaranteed that there is no edge between the two nodes before adding this one.
int shortestPath(int node1, int node2) returns the minimum cost of a path from node1 to node2. If no path exists, return -1. The cost of a path is the sum of the costs of the edges in the path.
 

Example 1:


Input
["Graph", "shortestPath", "shortestPath", "addEdge", "shortestPath"]
[[4, [[0, 2, 5], [0, 1, 2], [1, 2, 1], [3, 0, 3]]], [3, 2], [0, 3], [[1, 3, 4]], [0, 3]]
Output
[null, 6, -1, null, 6]

Explanation
Graph g = new Graph(4, [[0, 2, 5], [0, 1, 2], [1, 2, 1], [3, 0, 3]]);
g.shortestPath(3, 2); // return 6. The shortest path from 3 to 2 in the first diagram above is 3 -> 0 -> 1 -> 2 with a total cost of 3 + 2 + 1 = 6.
g.shortestPath(0, 3); // return -1. There is no path from 0 to 3.
g.addEdge([1, 3, 4]); // We add an edge from node 1 to node 3, and we get the second diagram above.
g.shortestPath(0, 3); // return 6. The shortest path from 0 to 3 now is 0 -> 1 -> 3 with a total cost of 2 + 4 = 6.
 

Constraints:

1 <= n <= 100
0 <= edges.length <= n * (n - 1)
edges[i].length == edge.length == 3
0 <= fromi, toi, from, to, node1, node2 <= n - 1
1 <= edgeCosti, edgeCost <= 106
There are no repeated edges and no self-loops in the graph at any point.
At most 100 calls will be made for addEdge.
At most 100 calls will be made for shortestPath.

*/

class Graph {
public:
    /*
        Intution /  Basic ALgorithm
        The following problem is a basic implemenation based problem 
        -Where we need to prepare the adjList from the given set if edges
        -Add a edge in the edges vector when the function is been called and it the same point of time update the adjList also
            because the addition of the edge will result in modification of the adjList as well
        -For calculationg the min distance between node 1 and node 2 
            Assume node 1 as the source and apply dijkstra algorithm and return the
            dist[node2] as the return parameter
        If the path does not exist the return -1
    
    */



    vector<vector<pair<int,int>>> adjList;
    vector<vector<int>> edges;
    Graph(int n, vector<vector<int>>& edges) {
        adjList.resize(n);
        for(auto &i:edges)
        {
            int u=i[0];
            int v=i[1];
            int cost=i[2];

            adjList[u].push_back({v,cost});

        }
    }
    
    void addEdge(vector<int> edge) {
        edges.push_back(edge);
        int u=edge[0];
        int v=edge[1];
        int cost=edge[2];
        adjList[u].push_back({v,cost});
    }
    
    int shortestPath(int node1, int node2) {
        int n=adjList.size();
        vector<int> dist(n,1e8);
        dist[node1]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,node1});
        while(!pq.empty())
        {
            int u=pq.top().second;
            int weight=pq.top().first;
            pq.pop();
            for(auto i:adjList[u])
            {
                int v=i.first;
                int w=i.second;
                if(dist[v] > weight + w)
                {
                    dist[v]=weight + w;
                    pq.push({weight+w,v});
                }
            }
        }
        return dist[node2]==1e8 ? -1 : dist[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */