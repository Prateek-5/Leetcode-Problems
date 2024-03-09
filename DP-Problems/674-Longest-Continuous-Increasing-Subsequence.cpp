/*
Given an unsorted array of integers nums, return the length of the longest continuous increasing subsequence (i.e. subarray). The subsequence must be strictly increasing.

A continuous increasing subsequence is defined by two indices l and r (l < r) such that it is [nums[l], nums[l + 1], ..., nums[r - 1], nums[r]] and for each l <= i < r, nums[i] < nums[i + 1].

 

Example 1:

Input: nums = [1,3,5,4,7]
Output: 3
Explanation: The longest continuous increasing subsequence is [1,3,5] with length 3.
Even though [1,3,5,7] is an increasing subsequence, it is not continuous as elements 5 and 7 are separated by element
4.
Example 2:

Input: nums = [2,2,2,2,2]
Output: 1
Explanation: The longest continuous increasing subsequence is [2] with length 1. Note that it must be strictly
increasing.
 

Constraints:

1 <= nums.length <= 104
-109 <= nums[i] <= 109
*/

class Solution {
public:
    /*
        Intution / Basic Algorithm

        -The following question si the build block of lis concept 
        Basically we need to find the lenght the of longest sub-array which is strictly incressing
        2 approch
        -Use an array to store the lenght of the longest incressing sub-array at every given index and keep a track of the max lis
        -Of use a count variale which gets reset if a non-incressing element is been encountred and incremments if a incressing
            element is been encountred
    
    
    */



    int findLengthOfLCIS(vector<int>& nums) {
        int n=nums.size();
        // vector<int> lis(n,1);
        int count=1;
        int maxi=1;
        for(int i=1;i<n;i++)
        {
            if(nums[i]>nums[i-1])
            {
                //lis[i]=lis[i-1]+1;
                count++;
            }
            else
            {
                count=1;
            }
            //maxi=max(maxi,lis[i]);
            maxi=max(maxi,count);

        }

        return maxi;



    }
};