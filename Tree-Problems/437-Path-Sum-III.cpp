/*
Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path equals targetSum.

The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes).

 

Example 1:


Input: root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
Output: 3
Explanation: The paths that sum to 8 are shown.
Example 2:

Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: 3
 

Constraints:

The number of nodes in the tree is in the range [0, 1000].
-109 <= Node.val <= 109
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
        Intution / Basic Algorithm
        -The following problems is similar to the find path problem just with a basic updations
        -As per the question the path need not start from the root node and need not end at the leaf node
        -For the above condition we need to consider each node as the root node
        -and for ending a path we can only end once we have reached nullptr
            that means even if we have reached the targetSum we cannot return rather we store our result in a 
            variable and recursivelly call for the right and left subtree and return the variable at end
        -The varibale holdes the number of time the path exist in the tree and is the return type of the function
        -Before calling the resursive function we substacr the node's value from the tragetSum

    
    
    
    
    */

    
    long long solve(TreeNode* root,long long targetSum)
    {
        if(root==nullptr)       return 0;
        targetSum=targetSum-root->val;
        int count=0;
        /*
            Note as discussed above we cannot return as soon as we have received the value we need to 
            store the result in a variable and if
                -At a particular node the sum is zero the count is 0
                -Plus the sum of count retunred for its's right and left recursive calls
                -Every node count is initialized by 0
        
        */
        if(targetSum==0)
        {
            count= 1;
        }
        count+=solve(root->left,targetSum);
        count+=solve(root->right,targetSum);
        return  count;

    }

    /*
        The following function is responcible for making every node as the root node and calling the solve function
        for the same 

        The count rrtuned from each node as the root node is been stored as an over all count  
    
    */
    void merge(TreeNode* root,int targetSum,int& total)
    {
        if(root==nullptr)   return;
        merge(root->left,targetSum,total);
        merge(root->right,targetSum,total);
        total+=solve(root,targetSum);
        return;
    }


    int pathSum(TreeNode* root, int targetSum) {

        int total=0;
        merge(root,targetSum,total);
        return total;
              
    }
};