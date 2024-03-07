/*
Given a binary tree root, a node X in the tree is named good if in the path from root to X there are no nodes with a value greater than X.

Return the number of good nodes in the binary tree.

 

Example 1:



Input: root = [3,1,4,3,null,1,5]
Output: 4
Explanation: Nodes in blue are good.
Root Node (3) is always a good node.
Node 4 -> (3,4) is the maximum value in the path starting from the root.
Node 5 -> (3,4,5) is the maximum value in the path
Node 3 -> (3,1,3) is the maximum value in the path.
Example 2:



Input: root = [3,3,null,4,2]
Output: 3
Explanation: Node 2 -> (3, 3, 2) is not good, because "3" is higher than it.
Example 3:

Input: root = [1]
Output: 1
Explanation: Root is considered as good.
 

Constraints:

The number of nodes in the binary tree is in the range [1, 10^5].
Each node's value is between [-10^4, 10^4].


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

        -Treat the following tree as a graph and apply dfs on it
        -Since it is a tree based graph we do not required an adjList to call for the dfs we can call it
            if the left and the right child of the node exist
        -For every node we pass a maxi parameter if the node value is greater than the maxi or equal we update the
            counter for the numberof good pairs alogo with the maxi value
        -The initial set of parameter passes the the root node and the root value
        -Note the condition only updates if the node value is equal or greater that the maxi
        -
    
    
    
    */

    void solve(TreeNode* source,int maxi,int& count)
    { 
        if(source->val >= maxi)
        {
            count++;
            maxi=max(maxi,source->val);
        }
        if(source->left!=nullptr)
        {
            solve(source->left,maxi,count);
        }
        if(source->right!=nullptr)
        {
            solve(source->right,maxi,count);
        }
        return;




    }


    int goodNodes(TreeNode* root) {
        int count=0;
        solve(root,root->val,count);
        return count;
    }
};