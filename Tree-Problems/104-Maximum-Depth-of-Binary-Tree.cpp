/*
Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: 3
Example 2:

Input: root = [1,null,2]
Output: 2
 

Constraints:

The number of nodes in the tree is in the range [0, 104].
-100 <= Node.val <= 100

*/

class Solution {
public:
    /*
        A recursive solution
    
    */

    int maxDepth(TreeNode* root) {
        if(root==nullptr){
            return 0;
            
        }
        return(max(maxDepth(root->left)+1,maxDepth(root->right)+1));
    }
};

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

        We need to implement the level order traversal and return the level as the answer 
    
    
    */



    int maxDepth(TreeNode* root) {
        if(root==nullptr)       return 0;
        queue<TreeNode*> q;
        q.push(root);
        int level=0; 
        while(!q.empty())
        {
            int count=q.size();
            for(int i=0;i<count;i++)
            {
                TreeNode* current=q.front();
                q.pop();
                if(current->left!=nullptr)      q.push(current->left);
                if(current->right!=nullptr)     q.push(current->right);
            }
            level++;

        }

        return level;


    }
};