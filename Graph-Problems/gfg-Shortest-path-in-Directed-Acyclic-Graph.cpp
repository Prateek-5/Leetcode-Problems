/*
Given a Directed Acyclic Graph of N vertices from 0 to N-1 and a 2D Integer array(or vector) edges[ ][ ] of length M, where there is a directed edge from edge[i][0] to edge[i][1] with a distance of edge[i][2] for all i.

Find the shortest path from src(0) vertex to all the vertices and if it is impossible to reach any vertex, then return -1 for that vertex.

Example1:

Input:
N = 4, M = 2
edge = [[0,1,2],[0,2,1]]
Output:
0 2 1 -1
Explanation:
Shortest path from 0 to 1 is 0->1 with edge weight 2. 
Shortest path from 0 to 2 is 0->2 with edge weight 1.
There is no way we can reach 3, so it's -1 for 3.
Example2:

Input:
N = 6, M = 7
edge = [[0,1,2],[0,4,1],[4,5,4],[4,2,2],[1,2,3],[2,3,6],[5,3,1]]
Output:
0 2 3 6 1 5
Explanation:
Shortest path from 0 to 1 is 0->1 with edge weight 2. 
Shortest path from 0 to 2 is 0->4->2 with edge weight 1+2=3.
Shortest path from 0 to 3 is 0->4->5->3 with edge weight 1+4+1=6.
Shortest path from 0 to 4 is 0->4 with edge weight 1.
Shortest path from 0 to 5 is 0->4->5 with edge weight 1+4=5.
Your Task:

You don't need to print or input anything. Complete the function shortest path() which takes an integer N as number of vertices, an integer M as number of edges and a 2D Integer array(or vector) edges as the input parameters and returns an integer array(or vector), denoting the list of distance from src to all nodes.

Expected Time Complexity: O(N+M), where N is the number of nodes and M is edges
Expected Space Complexity: O(N)

Constraint:
1 <= N <= 100
1 <= M <= min((N*(N-1))/2,4000)
0 <= edgei,0,edgei,1 < n
0 <= edgei,2 <=105

*/

class Solution {
  public:
  
    /*
        Intution / basic Algorithm
    
        -We are been provided with the edges vector and we need to find the Shortest Path in Directed Acyclic Graph
        
        We first need to find out the adjList from the given edges 
        And an important thing to not is while creating the AdjList we need to create a pair where 
            {vertex,weight}
        So that we can access the weight along with the adjList
        
        
        
        
        
        
        
    */
  
  
  
    
    vector<int> topologicalSort(vector<int>& inDegree,vector<vector<pair<int, int>>>& adjList)
    {
        
        queue<int> q;
        for(int i=0;i<inDegree.size();i++)
        {
            if(inDegree[i]==0)
            {
                q.push(i);
            }
        }
        
        vector<int> ans;
        while(!q.empty())
        {
            int current=q.front();
            ans.push_back(current);
            q.pop();
            for(auto i:adjList[current])
            {
                if(--inDegree[i.first]==0)
                {
                    q.push(i.first);
                }
                
            }
        }
        
        
        return ans;
        
        
        
        
    }
  
  
  
  
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges)
     {
        // code here
        
        vector<vector<pair<int, int>>> adjList(N);
        int count=edges.size();
        /*
            Creation of the AdjList with the cost factor aswell
        
        */
        for(int i=0;i<count;i++){
          int u=edges[i][0];
          int v=edges[i][1];
          int cost=edges[i][2];
          adjList[u].push_back({v,cost});
        }
        
        /*
            Calculate the inDegree of the following vertixes
        
        */
        
        vector<int> inDegree(N,0);
        for(auto i:adjList){
            for(auto j:i){
                inDegree[j.first]++;
            }
        }
        /*
            Find out the topological sort of the following graph
        
        */
        
        vector<int> topo=topologicalSort(inDegree,adjList);
        
        /*
            After calculatingthe topological sort we need to calculate the distance of all the nodes
        
        */
        
        vector<int> dist(N,INT_MAX);
        
       
        
        queue<int> q;
        
        for(int i:topo)
        {
            //cout<<i<<" ";
            q.push(i);
        }
        //cout<<endl;
        //0 1 4 5 2 3
    
        
        
        /*
            Initialize the distance of the source vertex as zero since the elements in the queue are been inserted 
            in the topological order we need not make any changes in the queue
        
        */
        
        
        dist[0]=0;
        //q.push(0);
        
        while(!q.empty())
        {
            int current=q.front();
            /*
                Featch out the top most element of the queue and store in the current varibale
            
            */
            q.pop();
            
            /*
                Iterate through all the adj vertexs of the current vertex
            
            */
            
            for(auto i:adjList[current])
            {
                /*
                    Extract the adj vertex and the weight of the edge from the current verex to the adj vertex
                    and compar
                        If the current distance of the adj vertex is greater than the dist we would obtain if we travel via 
                        the current vertex
                        
                */
                
                
                int v=i.first;
                int cost=i.second;
                /*
                    Below point is a very important point as if the distance of the current vertex is itself INT_MAX
                    that on assigning it to the other vertex + weight would not make any sence and would lead to
                    integer overflow condition so very-very important point
                
                */
                
                
                if(dist[current]==INT_MAX)      continue;
                if( dist[v] > dist[current] + cost )
                {
                    
                    dist[v]=dist[current]+cost;
                    q.push(v);
                }
            }
        }
        
        /*
            Since the answer require the vertex which are not reachiable to be marked as -1 the following loop is
            responcible for the same
        
        */
        
        for(int i=0;i<N;i++)
        {
            if(dist[i]==INT_MAX)
            {
                dist[i]=-1;
            }
        }
        
        return dist;
        
        
    }
    
    
};
