/*
You are given the root of a binary tree containing digits from 0 to 9 only.

Each root-to-leaf path in the tree represents a number.

For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
Return the total sum of all root-to-leaf numbers. Test cases are generated so that the answer will fit in a 32-bit integer.

A leaf node is a node with no children.

 

Example 1:


Input: root = [1,2,3]
Output: 25
Explanation:
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.
Therefore, sum = 12 + 13 = 25.
Example 2:


Input: root = [4,9,0,5,1]
Output: 1026
Explanation:
The root-to-leaf path 4->9->5 represents the number 495.
The root-to-leaf path 4->9->1 represents the number 491.
The root-to-leaf path 4->0 represents the number 40.
Therefore, sum = 495 + 491 + 40 = 1026.
 

Constraints:

The number of nodes in the tree is in the range [1, 1000].
0 <= Node.val <= 9
The depth of the tree will not exceed 10.


*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    /*
        Intution / Basic Algorithm

        -For the following problem we need to calculate the the sum of all the path from the root node to the leaf node
            and add it up
        -The base case for the following problem
            -If we have reached the null node return 
            -If we have reached the leaf node we add up the sum of the path to the actual totalSum variable
        -For each node we multiply the exisiting sum with 10 and then add the root->val 
        -Return the overall sum as the answer of the following problem
    
    
    
    */
    void solve(TreeNode* root,int currentSum,int& totalSum)
    {
        if(root==nullptr)       return;

        currentSum=10*currentSum+root->val;
        if(root->left==nullptr && root->right==nullptr)
        {
            totalSum+=currentSum;
            return;
        }

        solve(root->left,currentSum,totalSum);
        solve(root->right,currentSum,totalSum);

        return;



    }




    int sumNumbers(TreeNode* root) {
        int currentSum=0;
        int totalSum=0;
        solve(root,currentSum,totalSum);
        
        return totalSum;
    }
};