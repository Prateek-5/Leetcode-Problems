/*
You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].

Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where:

0 <= j <= nums[i] and
i + j < n
Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [2,3,0,1,4]
Output: 2
 

Constraints:

1 <= nums.length <= 104
0 <= nums[i] <= 1000
It's guaranteed that you can reach nums[n - 1].


*/


class Solution {
public:
    /*
        Intution / Basic Algorithm

        -In the following question need to min the number of jumps required to reach the last index
            given what it is certain that we will reach the last index

        Same logic as the Jump game we for
            -For each ith node we will iterate through all the node to the left of i
                0 - i-1 (jth index)
            -If we find an index with is reachable that means
                nums[j] + j > i -->Though this node we can reach ith and it can contribuye to a potential solution
            Once we habe the following confirmation for a particular node that throug this jth node we can reach the ith node
            then we will will update out dp[i] vector
                dp[i]=min(dp[i],dp[j]+1)
            what is min the min jumps required to reach thr jth index or the the current value that the dp[i] index is holding
            if the dp[j]!=INT_MAX to avoid over flow condition

            Please do the dry run of the following code for better undestanding
    
    
    
    
    */





    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,INT_MAX);
        dp[0]=0; //since the min jumps required for reaching the 0th index is 0 we are initialized it as 0
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[j] + j >= i) //reachable node
                {
                    if(dp[j]!=INT_MAX) //condition to avoid overflow
                    {
                        dp[i]=min(dp[i],dp[j]+1);
                    }
                }
            }
        }

        return dp[n-1];



    }
};