/*
You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
 

Constraints:

1 <= nums.length <= 104
0 <= nums[i] <= 105

*/

class Solution {
public:
    /*
        Intution / Basic Algorithm
        -Basically we are at the first index that's why i ahve initiallised the maxReach variable as 0
        -If at any index the index is gratter that the current reach value like
            [0,2]
        No notice if we are at 0th index thenw can never reach the next index buy jumping from 0 that's why 
        we have to include a confition if the 
            maxReach < i(index)
            that that means we are stuck at a particular index and the futher index are unreachable from there
            so we have to return flase in that case and we have returned it in the below code
        the max value of maxreach will always be the 
            maxReach=max(maxReach,i+nums[i])
        [2,3,1,1,4]
            currently we are at 0 index
        maxReach = max( 0 , 0+2) -> 2
        i=1 and maxReach is 2 that means we are at a safe index maxReach > i
        maxReach = max(maxReach , 1 + 3)
        the max jump can be the ith index which means that the we can reach the following index and how long 
        we can reach from the following index is represented by the num[index]
        that's why if maxReach > the last index then that means that we can traverse the array and reach the last index
        if not once the loop is over we cxan return false
    
    
    
    */



    bool canJump(vector<int>& nums) {
        int maxReach=0;
        if(nums.size()==1)  return true;
        for(int i=0;i<nums.size();i++)
        {
            if(maxReach<i)  return false;
            maxReach=max(maxReach,i+nums[i]);
            if(maxReach>=nums.size()-1)
            {
                return true;
            }
        }
        return false;
    }
};