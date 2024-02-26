/*
Given a weighted, undirected and connected graph of V vertices and an adjacency list adj where adj[i] is a list of lists containing two integers where the first integer of each list j denotes there is edge between i and j , second integers corresponds to the weight of that  edge . You are given the source vertex S and You to Find the shortest distance of all the vertex's from the source vertex S. You have to return a list of integers denoting shortest distance between each node and Source vertex S.
 

Note: The Graph doesn't contain any negative weight cycle.

 

Example 1:

Input:
V = 2
adj [] = {{{1, 9}}, {{0, 9}}}
S = 0
Output:
0 9
Explanation:

The source vertex is 0. Hence, the shortest 
distance of node 0 is 0 and the shortest 
distance from node 1 is 9.
 

Example 2:

Input:
V = 3, E = 3
adj = {{{1, 1}, {2, 6}}, {{2, 3}, {0, 1}}, {{1, 3}, {0, 6}}}
S = 2
Output:
4 3 0
Explanation:

For nodes 2 to 0, we can follow the path-
2-1-0. This has a distance of 1+3 = 4,
whereas the path 2-0 has a distance of 6. So,
the Shortest path from 2 to 0 is 4.
The shortest distance from 0 to 1 is 1 .
 

Your Task:
You don't need to read input or print anything. Your task is to complete the function dijkstra()  which takes the number of vertices V and an adjacency list adj as input parameters and Source vertex S returns a list of integers, where ith integer denotes the shortest distance of the ith node from the Source node. Here adj[i] contains a list of lists containing two integers where the first integer j denotes that there is an edge between i and j and the second integer w denotes that the weight between edge i and j is w.

 

Expected Time Complexity: O(V2).
Expected Auxiliary Space: O(V2).



*/

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    /*
        Create a minHeap to store the 
            {distance,vertes} of the corersponding vertex
        Create a distance vector to store the distance from the source node to the 
        multiple destination nodes
        
        An important logic in the minHeap we have to write a comperator function that compare the 
        p1.first(distance) and return the min distance and if the distance is same then it should 
        return based on p1.second that is the  vertex
        
        The first entry in the minHeap will be of the source vertex and it's distance which is zero then the corresponding
        adj vertex of the vertex will be inserted into the minHeap and as it is a minHeao the next vertes that wuould be 
        extracted would be the vertex with the min distance from the source and the whole process continues until the minHeap is empty 
    
    */
    
    
   
    
    
    
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        
        
         priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
        
        vector<int> dist(V,INT_MAX);
        //mark the distance for the source as 0
        dist[S]=0;
        //push the source and the distance for the source which is 0
        pq.push({0,S});
        //{distance,vertex} -->This is the manner in which we store the entrien in the minHeap
        
        while(!pq.empty())
        {
            pair<int,int> current=pq.top();
            pq.pop();
            
            /*
                current.first-->distance
                current.second-->vertex
            
            */
            
            for(auto i:adj[current.second])
            {
                int v=i[0];
                int cost=i[1];
                
                if(dist[v] > dist[current.second]+cost)
                {
                    dist[v]=dist[current.second]+cost;
                    pq.push({dist[v],v});
                }
                
            }
        }
        return dist;
        
        
    }
};
