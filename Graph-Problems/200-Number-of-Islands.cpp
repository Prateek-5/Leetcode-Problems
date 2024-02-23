/*
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is '0' or '1'.

*/

class Solution {
public:
    /*
        Sudo Code / Algorithm

        -Basically we have to calculate the number of island of we can say the number of collection of land cell's which are disjoint 
        -We can call a dfs function that well make all the connected land cells as 0 so the whole cluster will be covered at once
        -And we will keep a check at the caller side how many time the dfs function is been called 
        -The numebr of times the dfs function is been called is the number of island that we will return

        Function required for the following function
            -dfs function
            -main function where we will be ireratiing though the loop and call the dfs function
                -Based on the condition if(grid[i][j]='1')
                -Keep a count of the number of times the dfs fucntion is been called
    */


    bool isValid(int x,int y,vector<vector<char>>& grid){
        if(x<0 || x>=grid.size() || y<0 || y>=grid[0].size() || grid[x][y] !='1'){
            return false;
        }
        return true;
    }

    void dfs(int x,int y,vector<vector<char>>& grid){
        grid[x][y]='0';
        
        if(isValid(x+1,y,grid))     dfs(x+1,y,grid);
        if(isValid(x-1,y,grid))     dfs(x-1,y,grid);
        if(isValid(x,y+1,grid))     dfs(x,y+1,grid);
        if(isValid(x,y-1,grid))     dfs(x,y-1,grid);
    }

    int numIslands(vector<vector<char>>& grid) {
        int count=0;
          for(int i=0;i<grid.size();i++){
              for(int j=0;j<grid[0].size();j++){
                  if(grid[i][j]=='1'){
                      count++;
                      dfs(i,j,grid);
                  }
              }
            }
            return count;

        }
};