/*
You are given an undirected weighted graph of n nodes (0-indexed), represented by an edge list where edges[i] = [a, b] is an undirected edge connecting the nodes a and b with a probability of success of traversing that edge succProb[i].

Given two nodes start and end, find the path with the maximum probability of success to go from start to end and return its success probability.

If there is no path from start to end, return 0. Your answer will be accepted if it differs from the correct answer by at most 1e-5.

 

Example 1:



Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.2], start = 0, end = 2
Output: 0.25000
Explanation: There are two paths from start to end, one having a probability of success = 0.2 and the other has 0.5 * 0.5 = 0.25.
Example 2:



Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.3], start = 0, end = 2
Output: 0.30000
Example 3:



Input: n = 3, edges = [[0,1]], succProb = [0.5], start = 0, end = 2
Output: 0.00000
Explanation: There is no path between 0 and 2.
 

Constraints:

2 <= n <= 10^4
0 <= start, end < n
start != end
0 <= a, b < n
a != b
0 <= succProb.length == edges.length <= 2*10^4
0 <= succProb[i] <= 1
There is at most one edge between every two nodes.


*/


class Solution {
public:
    /*
        Intution / Basic Algorithm

        -Construct a adjList from the given edges and succProb
            -Looking at constraints we can see the at the length of succProb and edges will always be the same
                we can us it to comput our adjList
            -After cal the adjList we need to implement the dijkstra algorithm but with few modification
                -Since we do not need to min the distance as we always do
                -We need to maximize the dist so
                -In order to compute the max dist we need to use the maxHeap insted of minHeap
                -Initialize the dist vector with 0 (the lowest probility)
                -modify the relaxation condition to if(dist[v] < dist[u] + weight )     update!!!
                -return the dist[end_node] 
            Also node the probibility of 
                dist[v]=dist[u]*weight
            In probibility via u we multiply the probibility of u with the weight given

            -Also node that the length of edges will not always be equal to the number of vertex given in the question
            -In initial value that we feed in the dijkstra algo is {1,start_node}
            As in finding the min distance we insert the lowest possible value that is 0 and then the node(vertex)
            Here we insert the maximum possible value with the start_node(vertex)
            At the end return the dist[end_node]
    
    */


    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        
       // int n=edges.size();
        vector<vector<pair<int,double>>> adjList(n);
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            double weight=succProb[i];
            adjList[u].push_back({v,weight});
            adjList[v].push_back({u,weight});
        }


        /*
            The min possible value from probibility prespective is 0
        
        */
        vector<double> dist(n,0.0);
        


        /*
            We need to caluclate the max distance using the dijkstra algorith so we are using maxHeap
        
        */
        priority_queue<pair<double,int>,vector<pair<double,int>>> pq;

        dist[start_node]=1;

        pq.push({1,start_node});

        while(!pq.empty())
        {
            int u=pq.top().second;
            double weight=pq.top().first;
            pq.pop();
            for(auto i:adjList[u])
            {
                int v=i.first;
                double w=i.second;
                if(dist[v] <  weight* w )
                {
                    dist[v]=weight* w;
                    pq.push({weight*w,v});
                }
            }
        }
        

        return dist[end_node];

    }
};