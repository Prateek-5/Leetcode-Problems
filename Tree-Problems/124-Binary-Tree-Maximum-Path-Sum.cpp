/*
A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any non-empty path.

 

Example 1:


Input: root = [1,2,3]
Output: 6
Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.
Example 2:


Input: root = [-10,9,20,null,null,15,7]
Output: 42
Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.
 

Constraints:

The number of nodes in the tree is in the range [1, 3 * 104].
-1000 <= Node.val <= 1000



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
        The solution of the following problem is dependent on the fact we computer the following for each node
            -If only the root of the nodes is been included
            -If the root plus both it's children are been included
            -If the root and either of it;s children (the one which gives maximum)
        Out of the three values computed we need to calculate the max out of those and store it in a variable 
            and also calculate the maximum out of the variable also

        Note every node can not return all of the above three values computed as 
            Only root -->Accepted
            Root and either of it's children -->Accepted
            Root and both of it's children -->Not accepted as in that case if we look from top our path will divided into
                to direction and we are considering both the direction that is not a valid path .Hece we will be not returning
                those values
            
    
    
    
    */




    int maxSum;
    int solve(TreeNode* root)
    {
        if(root==nullptr)       return 0;

        int l=solve(root->left);
        int r=solve(root->right);

        int onlyRoot=root->val;
        int rootPlusBoth=l+r+root->val;
        int rootPlusOne=max(l,r)+root->val;


        maxSum=max(max(max(rootPlusBoth,rootPlusOne),onlyRoot),maxSum);



        return max(onlyRoot,rootPlusOne);


    }





    int maxPathSum(TreeNode* root) {
        maxSum=INT_MIN;
        solve(root);
        return maxSum;

    }
};

