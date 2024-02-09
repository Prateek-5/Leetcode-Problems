/*
Given an array of integers nums, sort the array in ascending order and return it.

You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the smallest space complexity possible.

 

Example 1:

Input: nums = [5,2,3,1]
Output: [1,2,3,5]
Explanation: After sorting the array, the positions of some numbers are not changed (for example, 2 and 3), while the positions of other numbers are changed (for example, 1 and 5).
Example 2:

Input: nums = [5,1,1,2,0,0]
Output: [0,0,1,1,2,5]
Explanation: Note that the values of nums are not necessairly unique.
 

Constraints:

1 <= nums.length <= 5 * 104
-5 * 104 <= nums[i] <= 5 * 104

*/


class Solution {

public:

    void merge(int low,int mid,int high,vector<int>& nums)
    {

        int left=low;   //the left half of the array is been represented by this variable
        int right=mid+1;    //the right side of the variable is been represented by this variable
        vector<int> temp;   //The following vector is been used to sore the mergerd values of the following interval
        while(left<=mid && right<=high){
            if(nums[left]<=nums[right]){
                temp.push_back(nums[left]);
                left++;
            }
            else{
                temp.push_back(nums[right]);
                right++;
            }
            /*
                The standard to merge the tow array based on the fact which element is lesser and increment the
                respective pointer accordingly.

            */

        }
        while(left<=mid){
            temp.push_back(nums[left]);
            left++;
        }
        while(right<=high){
            temp.push_back(nums[right]);
            right++;
        }
        //The above two case are used to represent he case where there are some elements left in the left or right 
        //as in the avove while we have used the && operator 

        for(int i=low;i<=high;i++){
            nums[i]=temp[i-low]; //i-low will represent the array as 0,1,2,3,4,5,6,7,8,9 etc
        }
        //the resultant array are been mergerged back to the original vector 

    }

    void mergeSort(int low,int high,vector<int>& nums){
        if(low>=high)   return; //the base case to stop the recursive call
        int mid=low+(high-low)/2;
        mergeSort(low,mid,nums);
        mergeSort(mid+1,high,nums);
        merge(low,mid,high,nums);   //call the merge function after computing the left and right half
    }




    vector<int> sortArray(vector<int>& nums) {
        /*
            We have to write 2 functions 
                Merge function
                MergeSort function
        */

        
        mergeSort(0,nums.size()-1,nums);
        return nums;









    }
};