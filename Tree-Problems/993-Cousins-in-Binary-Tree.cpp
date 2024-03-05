/*
Given the root of a binary tree with unique values and the values of two different nodes of the tree x and y, return true if the nodes corresponding to the values x and y in the tree are cousins, or false otherwise.

Two nodes of a binary tree are cousins if they have the same depth with different parents.

Note that in a binary tree, the root node is at the depth 0, and children of each depth k node are at the depth k + 1.

 

Example 1:


Input: root = [1,2,3,4], x = 4, y = 3
Output: false
Example 2:


Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true
Example 3:


Input: root = [1,2,3,null,4], x = 2, y = 3
Output: false
 

Constraints:

The number of nodes in the tree is in the range [2, 100].
1 <= Node.val <= 100
Each node has a unique value.
x != y
x and y are exist in the tree.



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

        -Do a level order traversal of the binary tree
        -Keep a boolean for the x and y variable at the start of each level and initialized it with false
        -If the value is found while traversal in the level flip the boolen to true
        -As it is mentioned in the question they should have different parent
        -We should make the queue which is used in the traversal to be a pair which store the current and parent Node
        -Once we have found the x or the y value we can retrive the value of their parent form the queue
        -Along with the vector of if x and y are found we can also store a variable to store the parent of the node
        -Once after the traversal of a level is compleated if both the variables are been fliped
            -We check for their parents if they are differenct
                -They are cousins
            -Else they are not
        -If we have iterated thorught the whole true without the above condition met return false
    
    
    */
    typedef pair<TreeNode*,TreeNode*> pt; 


    bool isCousins(TreeNode* root, int x, int y) {

        if(root->val ==x  || root->val==y)  return false;
        queue<pt> q;
        q.push({root,nullptr});

        bool xFound,yFound;
        while(!q.empty())
        {
            int count=q.size();
            xFound=false;
            yFound=false;
            int xParent,yParent;
            for(int i=0;i<count;i++)
            {   
                int current=q.front().first->val;
                
                TreeNode* currentNode=q.front().first;
                TreeNode* parentNode=q.front().second;


                q.pop();
                if(current==x)
                {
                    xFound=true;
                    xParent=parentNode->val;

                }
                if(current==y)
                {
                    yFound=true;
                    yParent=parentNode->val;
                }

                if(currentNode->left!=nullptr)
                {
                    q.push({currentNode->left,currentNode});
                }
                if(currentNode->right!=nullptr)
                {
                    q.push({currentNode->right,currentNode});
                }
            }
            if(xFound && yFound && xParent!=yParent)
            {
                return true;
            }

        }
        return false;

    }
};