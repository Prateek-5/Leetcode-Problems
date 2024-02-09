/*
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
 

Constraints:

n == nums.length
1 <= n <= 5 * 104
-109 <= nums[i] <= 109
 

Follow-up: Could you solve the problem in linear time and in O(1) space?

*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        /*
            The following solution is based on the voting algo
            ->The first part of the code is responcible to find out the the element which has the max frequency
            ->Initializing the res index as the 0th index and the count as 1 since all the element will have atleast 1 frequency
            ->Interate through the array and find if the element matches the nums[res] if 
                    yes increment the count++
                    if no decrement the count--
            -> If the count becomes 0 the replace the res variable with the current index and re-initialize the count variable to 1

            Once we ahe computed the element which as the max frequence then we need to interated thought the array 
            count the frequence and determince if the element is a majority elemen or not  

            The other approch are 2 nested loops and calculate the frequence of echa dn every element
            Using Hash Map and keep a check of the frequence of each and every element
            return the mp.first for which the mp.second> n/2
        
        
        */
        int res=0;
        int count=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[res]){
                count++;
            }
            else{
                count--;
            }
            if(count==0){
                res=i;
                count=1;
            }
        }
        cout<<nums[res];

        count=0;
        int reqCount=(nums.size())/2;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==nums[res]){
                count++;
            }
            if(count>reqCount){
                return nums[res];
            }
        }
        return -1;



    }
};