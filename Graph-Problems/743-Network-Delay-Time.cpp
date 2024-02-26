/*
You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.

 

Example 1:


Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
Output: 2
Example 2:

Input: times = [[1,2,1]], n = 2, k = 1
Output: 1
Example 3:

Input: times = [[1,2,1]], n = 2, k = 2
Output: -1
 

Constraints:

1 <= k <= n <= 100
1 <= times.length <= 6000
times[i].length == 3
1 <= ui, vi <= n
ui != vi
0 <= wi <= 100
All the pairs (ui, vi) are unique. (i.e., no multiple edges.)

*/

class Solution {
public:
    /*
        Intution / Basic Algorithm

        -The following is a problem where we have to compute the min time to deliver the message start form the
            source node which is k
        -We can implement dijkstra algorith to compute the min time for each node and return the max value from the 
            dist vector
        -Since we are given with the edges we first need to compute the adjList from the edges
        Impleamentions details
            The nodes are starting from 1
            Compute the adjList edges list is been given
    
    */



    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int,int>>> adjList(n+1);
        /*
            Computation of the adjList for the directed graph

        */

        for(auto i:times)
        {
            int u=i[0];
            int v=i[1];
            int w=i[2];

            adjList[u].push_back({v,w});
        }

        //minHeap declaration 
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        vector<int> dist(n+1,INT_MAX);
        //initialize the source distance as 0 standart practice
        dist[k]=0;
        /*
            Formate to implement data in minHead
                {distance,node}
        
        */
        pq.push({0,k});
        /*
            Below is the standard implementation for the dijkstra algorithm
        
        */
        while(!pq.empty())
        {
            int node=pq.top().second;
            int weight=pq.top().first;
            pq.pop();
            for(auto i:adjList[node])
            {   
                int v=i.first;
                int w=i.second;

                if(dist[v] > weight +w )
                {
                    dist[v]=weight+w;
                    pq.push({weight+w,v});
                }
            }
        }
        /*
            Since the nodes start form 1 we have considered the distances form 1 only and writted the logic
        
        */
        int maxi=INT_MIN;
        for(int i=1;i<=n;i++)
        {
            if(dist[i]==INT_MAX)      return -1;
            else{
                maxi=max(dist[i],maxi);
            }
        }

        return maxi;


    }
};


