/*
Given an integer array nums, return true if there exists a triple of indices (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k]. If no such indices exists, return false.

 

Example 1:

Input: nums = [1,2,3,4,5]
Output: true
Explanation: Any triplet where i < j < k is valid.
Example 2:

Input: nums = [5,4,3,2,1]
Output: false
Explanation: No triplet exists.
Example 3:

Input: nums = [2,1,5,0,4,6]
Output: true
Explanation: The triplet (3, 4, 5) is valid because nums[3] == 0 < nums[4] == 4 < nums[5] == 6.
 

Constraints:

1 <= nums.length <= 5 * 105
-231 <= nums[i] <= 231 - 1
 

Follow up: Could you implement a solution that runs in O(n) time complexity and O(1) space complexity?
*/

class Solution {
public:
    /*
        Intution / Basic Algorithm
        Find the longest incressing subsequence and if the length of the subsequence is 3 then return true
        We need to apply the same lis concept and if the lenght of the lis is return true else false
        But here since the constrain of array length is 
            1 <= nums.length <= 5 * 105
        out o(n*n) solution will not work here we need to come up with a better solution 
        One such way is binary Search + lis that gives o(nlogn) complexity

        For that need to mintain an array whose lenght gives us the max lis at any given point of time
        for every elemnt in the nus array we nned to find out the index of the lement which is 
        just larger that that nums[i] element if the index is found in the vector we update it's value with the 
        value in the present just larger elemtn in the vector
        If not found then we incress the size of the vector by adding the nums[i] element

        At any given point for time the lenght of the vector represents the length of the lis
        and also not ht evectoe thatwe are creating is sorted therefore we are using binary search in it 


    */

    int justlargerIndex(int element,vector<int>& sortedList)
    {
        int low=0;
        int high=sortedList.size()-1;
        int ans=-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(sortedList[mid] < element)
            {
                
                low=mid+1;
            }
            else if(sortedList[mid] >= element)
            {
                ans=mid;
                high=mid-1;
            }
        }
        return ans;
    }



    bool increasingTriplet(vector<int>& nums) {
     
        int n=nums.size();
        vector<int> sortedList;
        for(int i=0;i<n;i++)
        {
            int j=justlargerIndex(nums[i],sortedList);
            
            if(j==-1)
            {
                sortedList.push_back(nums[i]);
            }
            else{
                sortedList[j]=nums[i];
            }
            
            if(sortedList.size()>=3)    return true;
        }
        return false;





    }
}