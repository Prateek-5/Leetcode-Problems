/*
Given a weighted, undirected and connected graph of V vertices and E edges. The task is to find the sum of weights of the edges of the Minimum Spanning Tree. Given adjacency list adj as input parameters . Here adj[i] contains vectors of size 2, where the first integer in that vector denotes the end of the edge and the second integer denotes the edge weight.

 

Example 1:

Input:
3 3
0 1 5
1 2 3
0 2 1

Output:
4
Explanation:

The Spanning Tree resulting in a weight
of 4 is shown above.
Example 2:

Input:
2 1
0 1 5

Output:
5
Explanation:
Only one Spanning Tree is possible
which has a weight of 5.
 

Your task:
Since this is a functional problem you don't have to worry about input, you just have to complete the function spanningTree() which takes a number of vertices V and an adjacency list adj as input parameters and returns an integer denoting the sum of weights of the edges of the Minimum Spanning Tree. Here adj[i] contains vectors of size 2, where the first integer in that vector denotes the end of the edge and the second integer denotes the edge weight.

Expected Time Complexity: O(ElogV).
Expected Auxiliary Space: O(V2).
 

Constraints:
2 ≤ V ≤ 1000
V-1 ≤ E ≤ (V*(V-1))/2
1 ≤ w ≤ 1000
The graph is connected and doesn't contain self-loops & multiple edges.

*/
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	
	/*
	    Intution / Basic Algorithm
	    
	    -The following question demands the implementation of Prims Algorithm which is used to calculate the min Spanning Tree
	    
	    -Since we are given up with the edges vector firstly we will calculate the adjList form the given vector
	    -Now for Primes algorith implementation prespectiver we will require a min Heap to calculate the minimum distance
	        -Schema of the priority_queue
	            <int,pair<int,int> pq
	            pq.first -- >denoes the weight (which we wull min by the help of minHeap)
	            pq.second.first -->Node we are about to visit node / current node
	            pq.second.second -->The Parent node 
	    -We will require a visited vector to keep a track of the visisted nodes so that we do not get trapped in the endless loop
	    -We require a parent node so thatwe can have a idea from where we are comming . arriving at a particular node
	    IN case in future question we need to print the path
	    
	
	
	*/
	
	typedef pair<int,pair<int,int>> pt;
	
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        
        /*
            Creation of the adjList from the given edges vector
        */
       
        vector<vector<pair<int,int>>> adjList(V);
        for(int current=0;current<V;current++)
        {
            for(auto i:adj[current])
            {
                int u=current;
                int v=i[0];
                int weight=i[1];
            
            /*
                Since it is a undirected and connected graph we need to make 2 addition for each edge
            */
            
                adjList[u].push_back({v,weight});
                adjList[v].push_back({u,weight});
            }
            
            
        }
        
        //Declaration of the priority_queue (minHeap)
        priority_queue<pt,vector<pt>,greater<pt>> pq;
        
    
        vector<bool> visited(V,false);
        /*
            The visited vector is been maintained to keepp a record of all the vertex that have been included
            in the mst(minimum spanning tree)
            To avoid repeated addition of vertex and create in-accurate records
        
        */
        /*
            The parent vector is been created to keep a record of the parent node throught which we have add a
            node to the child node
            
        */
        
        vector<int> parent(V,-1);
        /*
            We initialize the prioprty_queue with the initial value of
            0 since there is node cost over head to inculde the first vertex
            0->Is the current Node
            -1-->Is the parent of the first node as the first node cannot have any parent
        
        */
        pq.push({0,{0,-1}});
        int sum=0;
        
        /*
            initialized the sum variable to 0
        
        */
        
        
        while(!pq.empty())
        {
            int currentNode=pq.top().second.first;
            int parentNode=pq.top().second.second;
            int weight=pq.top().first;
            pq.pop();
            /*
                If a particular node is been visited that means it already a partof mst so we 
                skip those iterations 
            
            */
            if(visited[currentNode]==true)  continue;
            
            /*
                If a particular vertex is not been included in the mst add it by the cost if the edge 
                that's why we are add the weight to the overall sum
                
                Once we have added the weight to the overall sum we mark the particulat vertex as visited
            
            */
            
            sum+=weight;
            visited[currentNode]=true;
            parent[currentNode]=parentNode;
            
            /*
                We will iterate throuch all the non-visited vertex of the current node
            
            */
            
            for(auto i:adjList[currentNode])
            {
                int v=i.first;
                int w=i.second;
                /*
                    Extract the information like the node and the edge weight
                    And only add those vertex which are not visited
                */
                
                if(visited[v]==false)
                {
                    
                    /*
                        Since the particular node is considered for addition through the currentNode
                        we add the parentValue to th payload and weight of edge and node
                    */
                    
                    pq.push({w,{v,currentNode}});
                }
                
                
            }
      
            
        }
        
        
        // cout<<"The parent array"<<endl;
        // for(int i:parent)
        // {
            
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        // cout<<"Visisted array"<<endl;
        // for(bool j:visited)
        // {
           
        //     cout<<j<<" ";
        // }
        // cout<<endl;
        
        return sum;
        
      
        
        
        
        
        
        
        
        
        
    }
};