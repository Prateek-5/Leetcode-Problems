
/*
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

 

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Example 3:

Input: coins = [1], amount = 0
Output: 0
 

Constraints:

1 <= coins.length <= 12
1 <= coins[i] <= 231 - 1
0 <= amount <= 104
*/
/*
    The following problem is a variation of the 0/1 knap sack problem 
        The requirement over here is to make the minimum number of coins required to make the given amount

        The intution behind the following proble is we will consider all the amount from 0-amount until which 
        For all the value we will be cal the min coins needed 

        for each amount we will initialize the it as INT_MAX which represent that the following amount cannot be made 

        for each ammount we will calculate the throung loop over the coin if the amount can be created or not

        condition check
            The coin value should not be greated that the amount fow whichwwe are trying to calculate
            the other case is if we are trying to cal the min amount besed on the previous data

                dp[i-count] In order to keep a chekc that we do not insert a integer overflow value in the array we
                kept a check for if dp[i-coin]!=INT_MAX
            return the dp[amount] if the value is INT_MAX return -1
            else return the dp[amount]



*/


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,INT_MAX);
        dp[0]=0;
        for(int i=1;i<=amount;i++){
            for(int coin:coins){
                if(coin<=i && dp[i-coin]!=INT_MAX){
                    dp[i]=min(dp[i],dp[i-coin]+1);
                }
            }
        }
        if(dp[amount]==INT_MAX)     return -1;
        else{
            return dp[amount];
        }
        
    }
};
