/*
You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

 

Example 1:


Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
Example 2:

Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
Example 3:

Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 10
grid[i][j] is 0, 1, or 2.


*/

class Solution {
public:
    /*
        Sudo Code / Algorithm

        -The basic idea of the fooliwng prble is to use bfs for the follwing question with a check for time
        -For each new cycle of the bfs if any updation happens we need to update the time factor
            To be discusses in deatin in the code below
        -Corner cases
            -If there are no fresh oranges in the grid return 0
            -If there are fresh oranges left in the grid after the bfa then return -1


    
    
    
    */


    /*
        this is a helper function which helps up in determinin if we can proceed up with the current index or not
    
    */
    bool isValid(int x,int y,vector<vector<int>>& grid){
        if(x<0 || x>=grid.size() || y<0 || y>=grid[0].size() || grid[x][y] != 1 ){
            return false;
        }
        return true;
    }




    int orangesRotting(vector<vector<int>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();

        deque<pair<int,int>> q;
        int fresh=0;//a counter for the fresh oranges if this is zero initially return 0

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push_back({i,j});
                }
                else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        //Below tow are the few corner casses thatwe need to check to minimize the below compuations
        if(fresh==0)        return 0;
        if(q.size()==0)     return -1;

        int time=0;
        //Code for the bfs begin here
        while(!q.empty()){
            int count=q.size();
            int temp=0;
            /*
                Note all the rotten oranges present in the queue will ritt the oranges parallely so 
                the time variable will be updated only once for the current set of queue element that's
                why we have restricted the iteration to the numberof elements present in the loop

                And the temp variable plays a significient role that is inly if any addition is been done in the queue
                that means a fresh orange is been moved from fresh -->rotten there is some work done it gets updated 
                if this variable is updated then it means we need to update the time varibale unless not 

            
            */



            while(count>0){
                pair<int,int> current=q.front();
                q.pop_front();
                int x=current.first;
                int y=current.second;


                int x_cord[]={-1,0,1,0};
                int y_cord[]={0,-1,0,1};
                for(int i=0;i<4;i++){
                    int x1=x+x_cord[i];
                    int y1=y+y_cord[i];
                    if(isValid(x1,y1,grid)){
                        temp++;
                        grid[x1][y1]=2;
                        q.push_back({x1,y1});
                    }
                }
                count--;
            }
            if(temp!=0){
                time++;
            }
        }
        /*
            Even after the bfs traveral if there are still fresh oranges present in the grid then we should return 
            -1 as it is not possible to update the followung orange

        
        */

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }


        return time;

    }
};