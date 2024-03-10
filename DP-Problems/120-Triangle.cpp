/*
Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

 

Example 1:

Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
Example 2:

Input: triangle = [[-10]]
Output: -10
 

Constraints:

1 <= triangle.length <= 200
triangle[0].length == 1
triangle[i].length == triangle[i - 1].length + 1
-104 <= triangle[i][j] <= 104
 

Follow up: Could you do this using only O(n) extra space, where n is the total number of rows in the triangle?

*/
class Solution {
public:
    /*
        Intution / Basic algorithm

        -The following question is beaed on the fact that we need to find the min path sum 
            so we will start from the bottom and go up in this process we will try to min the 
            sum by choseing the min from the given set for inputs

            like we are give a aconstrain the we can only move to i or i+1 we will use this for our 
            calculation
    
    
    
    */





    int minimumTotal(vector<vector<int>>& triangle) {
        int row=triangle.size();
        int col=triangle[row-1].size();
        vector<vector<int>> dp(row,vector<int>(col,0));

        for(int i=0;i<col;i++)
        {
            dp[row-1][i]=triangle[row-1][i];
        }

        for(int i=row-2;i>=0;i--)
        {
            col=col-1;
            for(int j=0;j<col;j++)
            {
                dp[i][j]=triangle[i][j] + min(dp[i+1][j],dp[i+1][j+1]);
            }
        }
        // for(auto &i:dp)
        // {
        //     for(auto &j:i)
        //     {
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }

        return dp[0][0];




    }
};
class Solution {
public:
    /*
        As per the follow up question this is the approch where we are only using the 
            O(n) space since  we i=only require the just before values for out calculation we need not
            store all the values in the 2-D array we can use tow differenct array of max O(n) space
            and can compute the result
    
    
    */

    int minimumTotal(vector<vector<int>>& triangle) {
        int row=triangle.size();
        int col=triangle[row-1].size();

        vector<int> prev(col,0);
        for(int i=0;i<col;i++)
        {
            prev[i]=triangle[row-1][i];
        }
        vector<int> curr(col,0);
        for(int i=row-2;i>=0;i--)
        {
            col=col-1;
           
            for(int j=0;j<col;j++)
            {
                curr[j]=triangle[i][j]+min(prev[j],prev[j+1]);
            }
            prev=curr;


        }

        return prev[0];




    }
};