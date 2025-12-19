/*

Given a binary tree, determine if it is height-balanced.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: true
Example 2:


Input: root = [1,2,2,3,3,null,null,4,4]
Output: false
Example 3:

Input: root = []
Output: true
 

Constraints:

The number of nodes in the tree is in the range [0, 5000].
-104 <= Node.val <= 104


*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

/*
      heigh balanced the difference between the right and left subtree should
   not be more than 1 for any sub-tree Sudo code

      wrie a function to calculate the height left and right heigh of each node
   present in the tree the return type of the following function will be int if
   a root node is encountered retunn 0 first calculate the left and right of the
   tree

   first we calculate the left height thre are few base case that we need to keep in mind while like if at any point the left sutree becomes unbalanced then at that very
   point it self we have to return -1 similar for right

   also keep in mind the check for the most important case of height of a tree the height is the max of the left and right

  */

int height(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    int left = height(root->left);

    if (left == -1)
        return -1;
    int right = height(root->right);
    if (right == -1)
        return -1;

    if (abs(left - right) > 1)
        return -1;

    return (1 + max(left, right));
}

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return height(root) != -1 ? true : false;
    }
};