/*
Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.

A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

All the visited cells of the path are 0.
All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
The length of a clear path is the number of visited cells of this path.

 

Example 1:


Input: grid = [[0,1],[1,0]]
Output: 2
Example 2:


Input: grid = [[0,0,0],[1,1,0],[1,1,0]]
Output: 4
Example 3:

Input: grid = [[1,0,0],[1,1,0],[1,1,0]]
Output: -1
 

Constraints:

n == grid.length
n == grid[i].length
1 <= n <= 100
grid[i][j] is 0 or 1

*/
class Solution {
public:
    /*
        Implement dijkstra using minHeap
            minHeap pair<int,pair<int,int>> {distance,{x_co-ordinate,y_co-ordinate}}
            Create a seperate vector for calculating the diatance
            write a custom fucntion to check if the index is out of bound or not
            Also from visited standpoint of view all the nodes that we visit we will mark it 
            as 1 or any other number to make sure we do not visite the same node again and again

            Since we are not provided with the adjList as other question we need to look out for all the
            available vertex from the current vertex by incrementing the co-ordinates and checking if they are 
            valid not nor similiar to some dfs based question in the past

            If the (n-1,n-1) node is not reacheble then we return -1
            Corner case if the starting node is not 0 then we return -1 right away

            we need to add 1 to the final answer as we are not including the cost of the first node that's why
            The thing that we calculate is the distance form the source node to the final node we also need to include the 
            first node as the question demands the length if the clear path



    */
    typedef pair<int,pair<int,int>> pt;

    bool isValid(int x,int y,vector<vector<int>>& grid)
    {

        if(x<0 || x>=grid.size() || y<0 || y>=grid[0].size() || grid[x][y]!=0){
            return false;
        }
        return true;

    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n=grid.size();
        priority_queue<pt,vector<pt>,greater<pt>> pq;
        vector<vector<int>> dist (n,vector<int>(n,INT_MAX));
        if(grid[0][0]==1)       return -1;
        pq.push({0,{0,0}});
        dist[0][0]=0;
        
        while(!pq.empty())
        {
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            grid[x][y]=1;
            int weight=pq.top().first;
            pq.pop();
            //cout<<"X:"<<x<<" "<<"Y:"<<y<<endl;

            int x1[]={0,1,0,-1,1,1,-1,-1};
            int y1[]={-1,1,1,0,0,-1,-1,1};

            for(int i=0;i<8;i++)
            {
                int x_cord=x+x1[i];
                int y_cord=y+y1[i];
                if(isValid(x_cord,y_cord,grid))
                {
                    if(dist[x_cord][y_cord] > weight +1)
                    {
                        dist[x_cord][y_cord] = weight +1;
                        pq.push({weight+1,{x_cord,y_cord}});
                    }

                }
            }

            
        }

        // for(auto i:dist)
        // {
        //     for(auto j:i)
        //     {
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }


        return dist[n-1][n-1]==INT_MAX ? -1 : dist[n-1][n-1]+1;






    }   
};
