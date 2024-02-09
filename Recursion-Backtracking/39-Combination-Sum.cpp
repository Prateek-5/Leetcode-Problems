/*
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the 
frequency
 of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

 

Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
Example 2:

Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]
Example 3:

Input: candidates = [2], target = 1
Output: []
 

Constraints:

1 <= candidates.length <= 30
2 <= candidates[i] <= 40
All elements of candidates are distinct.
1 <= target <= 40

*/


class Solution {
public:
    void combSum(int index,vector<int>& candidates,int target,vector<int> &curr,vector<vector<int>> &res){

        /*
            index==candidates is a base case to check if we ahve exusted all the elements of the array or not 
        
        */
        if(index==candidates.size()){
            if(target==0){
                res.push_back(curr); //the optimal condition to check if the following combination fits in
            }
            return;
            //we need to stop the recursive call once we have exusted all the elements
        }
        if(candidates[index]<=target){
            /*
                Including the following index in the resulatnt array and not incrementing the index
            */
            curr.push_back(candidates[index]);
            combSum(index,candidates,target-candidates[index],curr,res);
            curr.pop_back();
        }

        //Not including the resulatnt in the array and incrementing the index for the next element
        combSum(index+1,candidates,target,curr,res);
    }



    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        vector<vector<int>> res;
        /*
            In the following question we are maintaining 2 set of the vectors 
                1.to store the current permutation that we will be computing
                2. The set of the final resulatnt vector that would be retirned as answer
        */
        combSum(0,candidates,target,curr,res);
        return res;




    }
};