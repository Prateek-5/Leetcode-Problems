/*
Given an integer array nums that may contain duplicates, return all possible 
subsets
 (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
 

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10


*/

class Solution {
public:
    void solve(int index,vector<int>& nums,vector<vector<int>>& ans,vector<int>& curr){
        /*
            As we are concern abou the subset rather than a specific configuration
            we directly add the emene into the array
        */
        ans.push_back(curr);
        for(int i=index;i<nums.size();i++){
            //the followubg condition is to check if we do not have any dulpicate
            if(i!=index && nums[i]==nums[i-1])   continue;

            //include the element into the array 
            curr.push_back(nums[i]);
            solve(i+1,nums,ans,curr);
            //remove the element to so thatwe can also evaluate the not include case
            curr.pop_back();
        }
    }



    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        sort(nums.begin(),nums.end());
        //Sore the array because we have a duplication detection logic in-place
        solve(0,nums,ans,curr);

        return ans;

    }
};