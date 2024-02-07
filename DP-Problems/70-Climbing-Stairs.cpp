/*
    You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

 

Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
 

Constraints:

1 <= n <= 45

*/

/*
    The following problem can be solved using the fibonacci numbers methods

    Submitted solution
    class Solution {
public:
    /*

    Naive approch where we are considering the top-down approch where we are adding the number of ways 
    we can reach the 0th index by adding the n-1 and n-2 recursive call

    Base condition if we reched n==0 then we ahve reached a valid way 

    condition to check if we reached where the n is less than 0 the we are not considering that case and returning 0 

    int climbStairs(int n) {
        if(n==0){
            return 1;
        }
        if(n<0){
            return 0;
        }
        return (climbStairs(n-1)+climbStairs(n-2));

    }
    */

    /*
        This is the bottom up approch were we initialized the dp array of the 0th and the 1st index as both 
        contribute to a single way to climb 

        ex:- the number of ways to reach the 3rd step would be (no.of ways to reach the 1st) + (no. of ways to reach the 2nd step)

        similar logic we have applied in the solution

    
    
    */
    /*
     int climbStairs(int n) {
        vector<int> dp(n+1);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }

        return dp[n];

    }
    };



*/