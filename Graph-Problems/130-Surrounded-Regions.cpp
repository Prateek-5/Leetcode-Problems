/*
Given an m x n matrix board containing 'X' and 'O', capture all regions that are 4-directionally surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

 

Example 1:


Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
Explanation: Notice that an 'O' should not be flipped if:
- It is on the border, or
- It is adjacent to an 'O' that should not be flipped.
The bottom 'O' is on the border, so it is not flipped.
The other three 'O' form a surrounded region, so they are flipped.
Example 2:

Input: board = [["X"]]
Output: [["X"]]
 

Constraints:

m == board.length
n == board[i].length
1 <= m, n <= 200
board[i][j] is 'X' or 'O'.



*/
class Solution {
public:
    /*
        The folliwng question is basd on the concept of boundry traversal
            Basically we need to perform the in-place transformation in the matrix that all the regine that
            is been surrounded X in all four direction should be converted into X
        -The solution for the following problem is
            -We first need to initiate a special dfs call only for the boundry indexed as the cells that are connected through
            those indexes can never be a part of the surrounding region
            -All those connected boundry component should be replace with a special character that we have done in the boundry_Dfs fucntion 

            -Now for the remaining cell of 'O' that are remaining are all part of the the surrounding regine so we 
                -We will call the normal dfs function for the same and make in-place modification for those matrix element to 'X'
            -Now once we have done with the foolwing we will convert those special char that we updated instep 1 to normal '0'as to
            convert thsoe to 'B or some special char only means that we were trying to protect it from the normal recursive call

            -Once the following operation isbeen compleated we are left with the resultant array 
    
    
    
    */




    bool isValid(int x,int y,vector<vector<char>>& board){
        if(x<0 || x>=board.size() || y<0 || y>=board[0].size() || board[x][y]!='O'){
            return false;
        }
        return true;
    }
    //the following dfs is been made for the boundry index elements which have 0 in them
    void boundry_Dfs(int x,int y,vector<vector<char>>& board){
        board[x][y]='B';
        int x_cord[]={-1,0,0,1};
        int y_cord[]={0,1,-1,0};
        for(int i=0;i<4;i++){
            int x1=x+x_cord[i];
            int y1=y+y_cord[i];
            if(isValid(x1,y1,board))        boundry_Dfs(x1,y1,board);
        }
    }
    //that's the normal recursive call that is been made fo the the remaining index that are bound to the the surrounding index
     void dfs(int x,int y,vector<vector<char>>& board){
        board[x][y]='X';
        int x_cord[]={-1,0,0,1};
        int y_cord[]={0,1,-1,0};
        for(int i=0;i<4;i++){
            int x1=x+x_cord[i];
            int y1=y+y_cord[i];
            if(isValid(x1,y1,board))        dfs(x1,y1,board);
        }
    }




    void solve(vector<vector<char>>& board) {
        //First and last row traversal
        int m=board.size()-1;
        for(int i=0;i<board[0].size();i++){
            if(board[0][i]=='O')    boundry_Dfs(0,i,board);
            if(board[m][i]=='O')    boundry_Dfs(m,i,board);
        }

        //first and last col traversal
        int n=board[0].size()-1;
        for(int j=1;j<m;j++){
            if(board[j][0]=='O')    boundry_Dfs(j,0,board);
            if(board[j][n]=='O')    boundry_Dfs(j,n,board);     
        }

        //normal traversal to convert the '0' (surroundede region) to 'X'
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='O'){
                    dfs(i,j,board);
                }
            }
        }

        //here we are replaing the special char to normal '0' as those are not surrounded 
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='B'){
                    board[i][j]='O';
                }
            }
        }




    }
};