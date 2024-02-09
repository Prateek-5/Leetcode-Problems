/*
Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

 

Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
 

Constraints:

1 <= nums.length <= 105
-231 <= nums[i] <= 231 - 1
0 <= k <= 105
 

Follow up:

Try to come up with as many solutions as you can. There are at least three different ways to solve this problem.
Could you do it in-place with O(1) extra space?

*/


class Solution {
public:
    void swapArray(vector<int>& nums,int low,int high){
        while(low<high){
            swap(nums[low],nums[high]);
            low++;
            high--;
        }
    }



    void rotate(vector<int>& nums, int k) {
        k=k%nums.size();

        int n=nums.size()-1;
        if(nums.size()==1)      return;
        // swapArray(nums,0,n-k);
        // swapArray(nums,n-k+1,n);
        // swapArray(nums,0,n);

        /*
            The following above calls need to be made for the array when we have to rotate it by right

        */
        /*
            If we want to rotate the array by left then we have to make the we have to make the call 
            mentioned below in the code
            // swapArray(nums,0,k-1);
            // swapArray(nums,k+1,n);
            // swapArray(nums,0,n);


        */

    }
};