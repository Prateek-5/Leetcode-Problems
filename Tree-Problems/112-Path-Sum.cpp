/*
Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.

A leaf is a node with no children.

 

Example 1:


Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
Output: true
Explanation: The root-to-leaf path with the target sum is shown.
Example 2:


Input: root = [1,2,3], targetSum = 5
Output: false
Explanation: There two root-to-leaf paths in the tree:
(1 --> 2): The sum is 3.
(1 --> 3): The sum is 4.
There is no root-to-leaf path with sum = 5.
Example 3:

Input: root = [], targetSum = 0
Output: false
Explanation: Since the tree is empty, there are no root-to-leaf paths.
 

Constraints:

The number of nodes in the tree is in the range [0, 5000].
-1000 <= Node.val <= 1000
-1000 <= targetSum <= 1000

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
        Since we are expected to return if the path exist from the root node to the leaf node

        We can pass a initial call with the 
            root
            targetSum
        Base condition for out recursive call if we are at the leaf node and the targetSum=0
            we return true or else false;
        Also an important condition for us is if we reach the null node we need to return 
        
    
    */



    bool hasPathSum(TreeNode* root, int targetSum) {

        if(root==nullptr)   return false;
        targetSum=targetSum-root->val;
        if(root->left==nullptr && root->right==nullptr && targetSum==0)
        {
            return true;
        }
        
        return hasPathSum(root->left,targetSum) || hasPathSum(root->right,targetSum);

    }
};