/*
The problem is to find the shortest distances between every pair of vertices in a given edge-weighted directed graph. The graph is represented as an adjacency matrix of size n*n. Matrix[i][j] denotes the weight of the edge from i to j. If Matrix[i][j]=-1, it means there is no edge from i to j.
Do it in-place.

Example 1:

Input: matrix = {{0,25},{-1,0}}

Output: {{0,25},{-1,0}}

Explanation: The shortest distance between
every pair is already given(if it exists).
Example 2:

Input: matrix = {{0,1,43},{1,0,6},{-1,-1,0}}

Output: {{0,1,7},{1,0,6},{-1,-1,0}}

Explanation: We can reach 2 from 0 as 0->1->2
and the cost will be 1+6=7 which is less than 
43.
Your Task:
You don't need to read, return or print anything. Your task is to complete the function shortest_distance() which takes the matrix as input parameter and modifies the distances for every pair in-place.

Expected Time Complexity: O(n3)
Expected Space Complexity: O(1)

Constraints:
1 <= n <= 100
-1 <= matrix[ i ][ j ] <= 1000


*/


class Solution {
  public:
  
    /*
        Basic Intution / Algorithm
        
        The floyd warshall algorith is been used to detect the smallest distance between all the routes
        In Dijkstra we calculate the shortest distance between the source node and the destionation node
        
        But we we are given a task to compute all the shortest distance between all the nodes
        Like If 
            5 Vertex are there 1 ,2 ,3 ,4, 5
            
            we need to compute the shortest distance between 
                1 to 1,2,3,4,5
                2 to 1,2,3,4,5
                etc
            We use Floyd Warshall algorithm for the same and also it can be used to detect negative cycle
            
            Its an O(n^3) complexity algorith where we try to calculate the 
                like    1,2,3,4,5 vertex are there
                dist[1][2] is given 
                    We compute 
                        dist[1][1] + dist[1][2]     -->Distance between 1 and 2 via 1
                        dist[1][2] + dist[2][2]     -->Distance between 1 and 2 via 2
                        dist[1][3] + dist[3][2]     -->Distance between 1 and 2 via 3
                        dist[1][4] + dist[4][2]     -->Distance between 1 and 2 via 4
                        dist[1][5] + dist[5][2]     -->Distance between 1 and 2 via 5
                    and consider the min out of the following values and store it in dist[1][2]
                We do the similar process for all the vertex 
            We can also us the following algorithm to detect negative cycle
            Like if after the following computation the value in 
                dist[1][1] < 0
            The it means there is a negative cycle because pracitaclly also this value can never be anything else than 0
    
    
    */
    
  
  
  
	void shortest_distance(vector<vector<int>>&matrix){
	    // Code here
	    int m=matrix.size();
	    int n=matrix[0].size();
	    
	    /*
	        Since we compute the min value for the if there is no edge between the 2 vertex than 
	        we have to put a very large value in that place so that the -1 doest not affect the accurecy
	    
	    
	    */
	    
	    for(int i=0;i<m;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            if(matrix[i][j]==-1)
	            {
	                matrix[i][j]=1e8;
	            }
	        }
	    }
	    
	    
	    /*
	        Iterate throught all the vertex to calculate the distance via all of them
	    
	    */
	    
	    for(int via=0;via<m;via++)
	    {
	        for(int i=0;i<m;i++)
	        {
	            for(int j=0;j<n;j++)
	            {
	                matrix[i][j]=min(matrix[i][j], matrix[i][via] + matrix[via][j]);
	                /*
	                    Min diatance between i and j via 0,1,2,3,4....
	                    explained above in detail
	                
	                */
	            }
	        }
	    }
	    
	    /*
	    
	        Replace the 1e8 with with -1 as per the question ask
	    */
	    
	    for(int i=0;i<m;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            if(matrix[i][j]==1e8)
	            {
	                matrix[i][j]=-1;
	            }
	        }
	    }
	    

	    
	    
	    
	    
	}
};