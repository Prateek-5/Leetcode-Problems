/*
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return the number of distinct solutions to the n-queens puzzle.

 

Example 1:


Input: n = 4
Output: 2
Explanation: There are two distinct solutions to the 4-queens puzzle as shown.
Example 2:

Input: n = 1
Output: 1
 

Constraints:

1 <= n <= 9
*/

class Solution {
public:
    void solve(int col,vector<int> &prevrow,vector<int> &ud,vector<int> &ld,int n,int &count){
        /*
            Similar approch as of the N-Queen problem just the fact thatwe no longer require to keep the need
            of the actula vector<string> represntation just the hashed values and the based case of check if 
            we have exucted all the columns have been utilized 
        
        */
        if(col==n){
            count++;
        }
        for(int row=0;row<n;row++){
            if(prevrow[row]==0 && ud[n-1+col-row]==0 && ld[row+col]==0){
                
                prevrow[row]=1;
                ud[n-1+col-row]=1;
                ld[row+col]=1;

                solve(col+1,prevrow,ud,ld,n,count);

                prevrow[row]=0;
                ud[n-1+col-row]=0;
                ld[row+col]=0;
            }
        }
    }



    int totalNQueens(int n) {
        vector<int> prevrow(n,0);
        vector<int> ud(2*n-1,0);
        vector<int> ld(2*n-1,0);
        int count=0;
        solve(0,prevrow,ud,ld,n,count);
        return count;

    }
};