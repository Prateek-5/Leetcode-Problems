/*
There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.

 

Example 1:


Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
Output: 700
Explanation:
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 3 is marked in red and has cost 100 + 600 = 700.
Note that the path through cities [0,1,2,3] is cheaper but is invalid because it uses 2 stops.
Example 2:


Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1
Output: 200
Explanation:
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 2 is marked in red and has cost 100 + 100 = 200.
Example 3:


Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 0
Output: 500
Explanation:
The graph is shown above.
The optimal path with no stops from city 0 to 2 is marked in red and has cost 500.
 

Constraints:

1 <= n <= 100
0 <= flights.length <= (n * (n - 1) / 2)
flights[i].length == 3
0 <= fromi, toi < n
fromi != toi
1 <= pricei <= 104
There will not be any multiple flights between two cities.
0 <= src, dst, k < n
src != dst


*/

class Solution {
public:
    /*
        Intution / Basic Algorithm

        -Since we need to return the min cost to react the destination from the source with the given stops

        -We will create a adjList where we store where the vertex is headed to as this is a directed graph and price
        -We will initialized a dist vector with INT_MAX to store the min possible cost
        -AS we are given up with the source vertex we will insert it into the queue along with the initial cost which is 0 for source
        -Apply BFS with an addition constrain that if the destination is not reached withing k levels from the source we break the loop
        -And return the ans in dist[dst] what ever the value be 
    
    
    
    
    */



    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adjList(n);

        for(auto &i:flights)
        {
            int u=i[0];
            int v=i[1];
            int cost=i[2];

            adjList[u].push_back({v,cost});
        }



        vector<int> dist(n,INT_MAX);

        dist[src]=0;
        int level=0;
        queue<pair<int,int>> q;
        q.push({src,0});
        /*
            As we already know in bfs we traverse level by level 
                First at 1 distance
                second at 2 distance
                third at 2 distance etc
            We will apply the same logic to traverse from the source the queue.size() will store the vetixes that are at unit
             distance from the current vertex chosen
             
        
        
        */
        while(!q.empty() && level<=k)
        {
            int count=q.size();
            for(int i=0;i<count;i++)
            {   
                int current=q.front().first;
                int d=q.front().second;
                
                q.pop();

                for(auto &i:adjList[current])
                {
                    int v=i.first;
                    int cost=i.second;

                    if(dist[v] > cost+ d)
                    {
                        dist[v] =cost + d;
                        q.push({v,cost+d});
                    }
                }
            }
            level++;
        }
        return dist[dst]==INT_MAX ? -1 : dist[dst];






    }
};