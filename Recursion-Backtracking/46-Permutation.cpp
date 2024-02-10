/*
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]
Example 3:

Input: nums = [1]
Output: [[1]]
 

Constraints:

1 <= nums.length <= 6
-10 <= nums[i] <= 10
All the integers of nums are unique.

*/

class Solution {
public:
    void solve(vector<int>& curr,vector<bool>& freq,vector<vector<int>> &ans,vector<int>& nums)
    {
        //the base condition which check if the curr size is equal to the nums array size
        if(curr.size()==nums.size()){
            ans.push_back(curr);
        }
        //iterate through the loop to check for all elements
        for(int i=0;i<nums.size();i++){
            /*
                the below conditional check is to make sure 
                that we do not include the same elemt  mutiple time in the same permutation
            */ 
            if(freq[i]==false){

            //sice now we have decided to add the following into the stack we make it as true
                freq[i]=true;
                curr.push_back(nums[i]);
            //called the recursive function with included the index element
                solve(curr,freq,ans,nums);
            //undo the frequency marking to check for not include case
                freq[i]=false;
            //also remove the current element for the same 
                curr.pop_back();

            }
        }




    }






    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> curr;
        vector<vector<int>> ans;
        //he follwoing frequency array is been used to keep a track of the lements that are been added into the permulation
        vector<bool> freq(nums.size());

        solve(curr,freq,ans,nums);

        return ans;



    }
};