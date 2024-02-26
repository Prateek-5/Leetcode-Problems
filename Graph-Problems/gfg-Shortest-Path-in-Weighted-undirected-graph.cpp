/*
You are given a weighted undirected graph having n vertices numbered from 1 to n and m edges describing there are edges between a to b with some weight, find the shortest path between the vertex 1 and the vertex n and if path does not exist then return a list consisting of only -1.

Note - 
1. If there exists a path, then return a list whose first element is the weight of the path.
2. If no path exists then return a list containing a single element -1.

Example:
Input:
n = 5, m= 6
edges = [[1,2,2], [2,5,5], [2,3,4], [1,4,1],[4,3,3],[3,5,1]]
Output:
5 1 4 3 5
Explaination:
Shortest path from 1 to n is by the path 1 4 3 5 whose weight is 5. 

Your Task:
You don't need to read input or print anything. Your task is to complete the function shortestPath() which takes n vertex and m edges and vector of edges having weight as inputs and returns the shortest path between vertex 1 to n.

Expected Time Complexity: O(m* log(n))
Expected Space Complexity: O(n)

Constraint:
2 <= n <= 105
0 <= m <= 105
0<= a, b <= n
1 <= w <= 105

*/

class Solution {
  public:
  
  /*
    
        Implement the dijkstar algorith with an addition parent vector and we can later iterate through the parent vector 
        to find out the corresponding path
        
        Implementation Details
        
            We are given edges vector hence we need to compute the adjList from the given parent vector
            After calculating the adj we need to implement the dijkstar algorithm either by minHeap or by set
            During the computation of the shortest path we neded to maintain a parent array in-order to store
            that the min distance that we are caluclating is via which vertex
            
            After we are done with the same we call the getPath function where we calculate the 
            path based on the fact that the parent of the souce node is the node itself it serves as the 
            bases case for out recursive call
        
        
  
  
  */
  
  
    void getPath(int n,vector<int>& parent,vector<int>& ans)
    {
       // cout<<"The nodes in the path"<<n<<endl;
        if (parent[n] == n)
        {   
            // the source node gets inserted first
            ans.push_back(n);
            return;
        }

        getPath(parent[n], parent, ans);
        //once the function retreaces all the remaining nodes gets inserted in the array
        ans.push_back(n);
        
        
        
    }
  
  
  
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        
        vector<vector<pair<int,int>>> adjList(n+1);
        
        for(auto i:edges)
        {
            
            /*
                Since it is a weighted undirected graph we need to add 2 vertex for every coresponding node and 
                we are adding pair because we need addition information regarding the weight of the edges
            */
            
            adjList[i[0]].push_back({i[1],i[2]});
            adjList[i[1]].push_back({i[0],i[2]});
        }
        
        /*
            Since the edges start from 1 to n we have considered the vector size as n+1
        */
        
        vector<int> dist(n+1,INT_MAX);
        //priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        set<pair<int,int>> st;
        
        /*
            {distance,vertex}
            this is the formate in which we insert the data in the minHeap
        
        */
        
        vector<int> parent(n+1);
        for(int i=1;i<=n;i++)   parent[i]=i;
        parent[1]=1;
        dist[1]=0;
        //pq.push({0,1});
        st.insert({0,1});
        while(!st.empty())
        {
            // int node=pq.top().second;
            // int weight=pq.top().first;
            // pq.pop();
            
            auto it= *st.begin();
            int node=it.second;
            int weight=it.first;
            st.erase(it);
            
            
            
            for(auto i:adjList[node])
            {
                
                int v=i.first;
                int w=i.second;
                
                if(dist[v] > weight +w)
                {
                    dist[v]=weight+w;
                    parent[v]=node;
                    //pq.push({weight+w,v});
                    st.insert({weight+w,v});
                    
                }
                
            }
            
        }
        
        /*
            As per the question we the final node is not reachable that is its diatance is INT_MAX
            then we have to return -1 in a vector formate hence the below condition
        
        */
        vector<int> ans;
        if(dist[n]==INT_MAX)
        {
            return {-1};
        }
        
        ans.push_back(dist[n]);
        getPath(n,parent,ans);
        
        
        
        return ans;
        
        
        
        
        
    }
};
