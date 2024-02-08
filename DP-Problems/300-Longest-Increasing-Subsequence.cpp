/*
Given an integer array nums, return the length of the longest strictly increasing 
subsequence
.

 

Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4
Example 3:

Input: nums = [7,7,7,7,7,7,7]
Output: 1
 

Constraints:

1 <= nums.length <= 2500
-104 <= nums[i] <= 104
 

Follow up: Can you come up with an algorithm that runs in O(n log(n)) time complexity?

*/

/*
    The following is a a problem is based on the Longest incressing subsequence
    for the follwing proble we calculate the longest incressing subsequence of each and every element in the array

    And for each element we go to the right of the array and find if any element is less than the current elemtn if yes then 
    we compare the current dp[i] with the dp[j](the element which is less than the current index )

    Along the same loop we keep a check for the max value tahtwe have incountred in the dp array and retunr the same max value

    The time complexity O(n^2)
    The is a better version of the problem where we caluclate it in o(nlogn)
    
    

*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        int res=1;
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(nums[j]<nums[i]){
                    dp[i]=max(1+dp[j],dp[i]);
                }
            }
            res=max(res,dp[i]);
        }
        return res;

    }
};