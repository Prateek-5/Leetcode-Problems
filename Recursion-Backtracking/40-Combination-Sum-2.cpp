/*
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

 

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]
 

Constraints:

1 <= candidates.length <= 100
1 <= candidates[i] <= 50
1 <= target <= 30



*/

class Solution {
public:
    void compSum(int index,vector<int>& curr,int target,vector<int>& candidates,vector<vector<int>>& res){
        if(target==0){
            //the base condition to check if the following is a valid combination or not
            res.push_back(curr);
            return;
        }
        //We will be iterationg throung the whole array 
        for(int i=index;i<candidates.size();i++){
            //the below condition checks if we are not considering the dulplicates in our solution 
            if(i>index && candidates[i]==candidates[i-1])    continue;

            //Since the element which is greater thn the current target will bot add up to the solution we are breaking the loop here
            if(target<candidates[i]) break;
            
            //considering the lement for the solution hence adding it to the curr array
            curr.push_back(candidates[i]);
            //since we are not allowed to consider the same element multiple time we are incrementing the index
            compSum(i+1,curr,target-candidates[i],candidates,res);
            //once added remove the element from the curr vector
            curr.pop_back();
        }


    }



    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        //sort the array since we have logic in-place to detect the duplicates 
        vector<int> curr;
        vector<vector<int>> res;
        compSum(0,curr,target,candidates,res);
        return res;
    }
};