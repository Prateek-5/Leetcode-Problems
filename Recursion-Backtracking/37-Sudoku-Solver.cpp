/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.

 

Example 1:


Input: board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
Output: [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
Explanation: The input board is shown above and the only valid solution is shown below:


 

Constraints:

board.length == 9
board[i].length == 9
board[i][j] is a digit or '.'.
It is guaranteed that the input board has only one solution.

*/

class Solution {
public:
    bool solve(vector<vector<char>>& board){
        /*
            We have to iterate through the whole board to find out which index is empty
            for finding that particular index we have to iterate throught the loop

        */
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){

                //the condition check to find out the empty value in the board 
                if(board[i][j]=='.'){
                    //we can place any value at that particular index so we are iterating through it 1-9 
                    for(char c='1';c<='9';c++){
                        //we will call the helper function to if we can place that particualar value or not
                        if(isValid(board,i,j,c)){
                            board[i][j]=c;
                        
                        /*
                            After placing that value we call the resursive function as the board vector is been passed
                            by reference the updation will happen inplace
                        */
                        
                        if(solve(board)){
                           
                           //if subsequent recursive function return's true we will also return true
                            return true;
                        }
                        else{
                            /*
                            if the subsequent resursive function return false then that particular value is not fit for 
                            the following place so we empty it to check for another value
                            */ 
                            board[i][j]='.';
                        }
                    }
                    }
                    //of non of the combination fits in then we return false
                    return false;
                }
            }
        }
        //Once we have iterate throug the whole board that means no more element left so we return true;
        return true;
    }
    /*
        The following id the helper function whchi checks if the corresponding value taht we are trying to enter  in the grid s
        not present in the respective row or column or the gird of the folliwng sudoku
    
    */
    bool isValid(vector<vector<char>>& board,int row,int col,char c){
        for(int i=0;i<9;i++){
            if(board[row][i]==c) return false;
            if(board[i][col]==c)    return false;
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==c)
            {
                return false;
            }
        }
        return true;
    }




    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }

};

