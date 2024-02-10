/*

The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

 

Example 1:


Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
Example 2:

Input: n = 1
Output: [["Q"]]
 

Constraints:

1 <= n <= 9


*/

class Solution {
public:


    void solve(int col,vector<string>& curr,vector<vector<string>>& ans,vector<int> &prevrow,vector<int> &ud,vector<int> &ld,int n){
        
        /*
            The following is the bae case to keep the track of the if we have exusted all the colums that
            means we have arrived at a fisible solution
        */
        if(col==n){
            ans.push_back(curr);
            return;
        }
        for(int row=0;row<n;row++){
            /*
                For each column we will iterate through eacha nd every column that's why this loop

                below are the look up condition that we have to see if if any of the value is 1 it means 
                that quene is present in that particular diraction hence we should avoid those iterations

            
            
            */
            if(prevrow[row]==0 && ud[n-1+col-row]==0 && ld[row+col]==0){
                curr[row][col]='Q';
                prevrow[row]=1;
                ud[n-1+col-row]=1; 
                ld[row+col]=1;
                solve(col+1,curr,ans,prevrow,ud,ld,n);
                curr[row][col]='.';
                prevrow[row]=0;
                ud[n-1+col-row]=0; 
                ld[row+col]=0;
            }
        }

        /*
            Once we have finialized the position for the queen then we will recursivelly call the next combination
            witha an incremented column and also make sure the backtracking approch to pop out the result so that we can have a check 
            for the iclude and not include case and we also need to resent the hashed value as we have removed the value

        */

    }



    vector<vector<string>> solveNQueens(int n) {

        /*
            The variables and vector are defined fo the following purpose

            ans to store the final result
            curr to store the current permulation
            prevrow -->to keep the track of the prev row if present if quent is there or not lookup method prevrow[row]
            ud-->upperdiagonal -->to keep a track of the upper diagonal lookup n-1+col-row
            ld-->lowerdiagonal -->to keep a track of the lower diagonal lookup row+col
        
        */


        vector<vector<string>> ans;
        vector<string> curr(n);
        string s(n,'.');
        for(int i=0;i<n;i++)    curr[i]=s;
        vector<int> prevrow(n,0);
        vector<int> ud(2*n-1,0);
        vector<int> ld(2*n-1,0);
        solve(0,curr,ans,prevrow,ud,ld,n);
        return ans;

    }
};