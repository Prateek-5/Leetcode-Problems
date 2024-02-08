/*

Given an integer array nums of unique elements, return all possible 
subsets
 (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
 

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
All the numbers of nums are unique.



*/
/*
    the following problem is a classical case of the include and not include problem 

    In this we have to return the all possible combination subsequence of the array
    as shown above

    for each recursive call we are all the function for two cases
        Include the current element in the resultant array for the same curr.push_back(nums[index]);

        Since the inculde permutation is been calculated we now check the not include computation
        for the same we are call curr.pop_back()
            which woule result inremoving the previously added element for the cuu array
        and now after removing basically excluding the element we are again incrementing the index

        for the same we are calling the solve (index+1..)
        for the base case we ahave kept the check for the index variable equal to the size of the array 
        Note it is not important that the size of the curr array will always be equal to the nums array 
        buy for add the permuation to the resultant array th eindex sjould always be equal to the resultant array
        




*/
class Solution {
public:

int n;

    void solve(int index,vector<int>& nums,vector<vector<int>> &res,vector<int> &curr){
        if(index==n){
            res.push_back(curr);
            return;
        }
        //include
        curr.push_back(nums[index]);
        solve(index+1,nums,res,curr);
        curr.pop_back();
        //not inculde
        solve(index+1,nums,res,curr);
    }



    vector<vector<int>> subsets(vector<int>& nums) {
        n=nums.size();
        vector<vector<int>> res;
        vector<int> curr;
        solve(0,nums,res,curr);

        return res;

    }
};

