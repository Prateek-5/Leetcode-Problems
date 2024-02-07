/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 2:

Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 400


*/

//Solution
/*
    class Solution {
public:

    /*
        The follwoing is a brute force solution if the include nd not include approch 
        of the dp problem set where in this we have applied the concept of including and adding the
        the amount and then subtracting -2 for the nth index as we are not allowed to robe the adjecent house 

        And  the another recursive call is of the function where are are not robbing the house and only decrementing -1 from 
        the nth index  
    
    */
    int solve(vector<int>& nums,int n){
        if(n==0){
            return nums[0];
        }
        if(n<0)     return 0;
        else{
            return max(nums[n]+solve(nums,n-2),solve(nums,n-1));
        }

    }

    /*
        Below is the optimized aproch of the problem where we have created a dp array and went bottom up in the solution
        the based case will be the same as above

        The important point to note is the fact that the 1st index the 2nd element of the dp array will be the 
            max of nums[0] and num[1] as we can not apply the logic of dp[i]=max(dp[i-1],nums[i]+dp[i-2])

        The logic of remains the same as above 

        Nore for the following proble we have considered size of the dp array and the nums arrays as the same 
         
    
    */


    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)    return nums[0];

        // return solve(nums,n);
        vector<int> dp(n);
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
            dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
        }

        return dp[n-1];
    
        
    }
};



*/