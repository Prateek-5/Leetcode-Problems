/*
You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.
Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Total profit is 4.
Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.
 

Constraints:

1 <= prices.length <= 3 * 104
0 <= prices[i] <= 104
*/

class Solution {
public:
    /*
        Intution / Basic Algorithm

        basically in the following question there are 2 parameters that are changing 
            -index
            -buy flag
        We will start from the 0th index with the flag of buy with 1 and and continue until the nth index
        -In the following process we will calculate the the profit for each index based on the flag
        -if the flag is true that means we can buy it that particular index
            -include the value as -prices[index] and move to next node with buy flag flipped
            - do not include the value not price added and movde to the next flag with the buy flag as it is
        -Simialr process for sell
    
    
    
    
    */








    // int maxProfit(int index,int buy,vector<int>& prices)
    // {
    //     if(index==prices.size())
    //     {
    //         return 0;
    //     }
    //     int profit;
    //     if(buy==1)
    //     {
    //         profit=max(-prices[index]+maxProfit(index+1,0,prices),0+maxProfit(index+1,1,prices));
    //     }
    //     else
    //     {
    //         profit=max(prices[index]+maxProfit(index+1,1,prices),maxProfit(index+1,0,prices));
    //     }

    //     return profit;

    // }
    int maxProfit(int index,int buy,vector<int>& prices,vector<vector<int>>& dp)
    {
        if(index==prices.size())
        {
            return 0;
        }
        if(dp[index][buy]!=-1)      return dp[index][buy];
        int profit;
        if(buy==1)
        {
            profit=max(-prices[index]+maxProfit(index+1,0,prices,dp),0+maxProfit(index+1,1,prices,dp));
        }
        else
        {
            profit=max(prices[index]+maxProfit(index+1,1,prices,dp),maxProfit(index+1,0,prices,dp));
        }

        return dp[index][buy]=profit;

    }



    int maxProfit(vector<int>& prices) {
        
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int> (2,-1));

        return maxProfit(0,1,prices,dp);

    }
};