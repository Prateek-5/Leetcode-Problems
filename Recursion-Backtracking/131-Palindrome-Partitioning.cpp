/*
Given a string s, partition s such that every 
substring
 of the partition is a 
palindrome
. Return all possible palindrome partitioning of s.

 

Example 1:

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
Example 2:

Input: s = "a"
Output: [["a"]]
 

Constraints:

1 <= s.length <= 16
s contains only lowercase English letters.

*/
class Solution {
public:

    void solve(int index,string s,vector<string>& curr,vector<vector<string>>& res){
        //the following is the base case regarding if we have exusted the string or not 
        if(index==s.size()){
            res.push_back(curr);
            return;
        }

        //we will iterate throug the index element and until the end of the string
        for(int i=index;i<s.size();++i){
            //only call recursion for those substr which are palindrome
            if(isPalindrome(s,index,i)){
                //inser the respective sub-string and call the recursion for the next index
                curr.push_back(s.substr(index,i-index+1));

                
                solve(i+1,s,curr,res);

                //similar for backtracking check for the not-include case
                
                curr.pop_back();
            }
        }

    }
    /*
        the following in a helper function to check if the substr is a palindrome or not
    */ 
    bool isPalindrome(string s,int start,int end){
        while(start<=end){
            if(s[start]!=s[end]){
                return false;
            }
            else{
                start++;
                end--;
            }
        }
        return true;
    }


    vector<vector<string>> partition(string s) {
        vector<string> curr;
        vector<vector<string>> res;

        solve(0,s,curr,res);
        return res;

    }
};

