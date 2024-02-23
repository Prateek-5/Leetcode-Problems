/*
You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

The area of an island is the number of cells with a value 1 in the island.

Return the maximum area of an island in grid. If there is no island, return 0.

 

Example 1:


Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
Output: 6
Explanation: The answer is not 11, because the island must be connected 4-directionally.
Example 2:

Input: grid = [[0,0,0,0,0,0,0,0]]
Output: 0
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 50
grid[i][j] is either 0 or 1.
*/

class Solution {
public:
    /*
        Dfs based solution 
            -Write a normal dfs fucntion with an added parameter of count passed by reference 
            -Before each dfs call initialize the count to 0
            -Once we return from the dfs call compare it with the maxCount 
            -return the maxCount ate the end of the function
    */

    bool isValid(int x,int y,vector<vector<int>>& grid){
        if(x<0 || x>=grid.size() || y<0 || y>=grid[0].size() || grid[x][y]!=1){
            return false;
        }
        return true;
    }


    void dfs(int x,int y,vector<vector<int>>& grid,int &count){
        grid[x][y]=0;
        count++;
        int x_coord[]={-1,0,1,0};
        int y_coord[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int x1=x+x_coord[i];
            int y1=y+y_coord[i];
            if(isValid(x1,y1,grid))     dfs(x1,y1,grid,count);
        }
    }







    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int count=0;
        int maxCount=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1){
                    count=0;
                    dfs(i,j,grid,count);
                    maxCount=max(count,maxCount);

                }
            }
        }
        return maxCount;


    }
};