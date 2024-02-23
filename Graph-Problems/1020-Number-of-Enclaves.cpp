/*
You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

 

Example 1:


Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
Output: 3
Explanation: There are three 1s that are enclosed by 0s, and one 1 that is not enclosed because its on the boundary.
Example 2:


Input: grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
Output: 0
Explanation: All 1s are either on the boundary or can reach the boundary.
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 500
grid[i][j] is either 0 or 1.

*/

class Solution {
public:

    /*
        Sudo Code / Algorithm

        -The approch for the folliwng problem is we need to eliminate the land cells that are connect ot the boundry index
        -We will call dfs for the land cell tht are there in the boundry index
        -The folliwng dfs call will convert all the land cells that are connect to the bound to 0 and we are only left with the 
            cells that are not connected to the boundry
        -We will iterate through 2 nested loop through the maxtix and keep a count of the remaining land cell(which are not connect to the boundry)
        -And return the result 


        -To solve the following proble we need th follwing function
            -A loop that's specifally for the boundry indexes
            -dfs function 
            -A helper function that determines if we can call the dfs for the particulat index or not 
    
    
    
    
    */

    bool isValid(int x,int y,vector<vector<int>>& grid){
        if(x<0 || x>=grid.size() || y<0 || y>=grid[0].size() || grid[x][y]!=1){
            return false;
        }
        return true;
    }

    void dfs(int x,int y,vector<vector<int>>& grid){
        grid[x][y]=0;
        if(isValid(x+1,y,grid))     dfs(x+1,y,grid);
        if(isValid(x-1,y,grid))     dfs(x-1,y,grid);
        if(isValid(x,y+1,grid))     dfs(x,y+1,grid);
        if(isValid(x,y-1,grid))     dfs(x,y-1,grid);

    }






    int numEnclaves(vector<vector<int>>& grid) {
        
        /*
            Boundry Traversal
        */
        int m=grid.size()-1;//row number

        for(int i=0;i<grid[0].size();i++){
            if(grid[0][i]==1){
                dfs(0,i,grid);
            }
            if(grid[m][i]==1){
                dfs(m,i,grid);
            }
        }
        int n=grid[0].size()-1;
        for(int j=1;j<grid.size()-1;j++){
            if(grid[j][0]==1){
                dfs(j,0,grid);
            }
            if(grid[j][n]==1){
                dfs(j,n,grid);
            }
        }
        //loop through the remaining element and coun the number of land cells

        int count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    count++;
                }
            }
        }
        return count;



    }
};