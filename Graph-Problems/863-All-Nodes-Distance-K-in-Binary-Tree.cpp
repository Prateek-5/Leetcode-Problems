/*
Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.

You can return the answer in any order.

 

Example 1:


Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
Output: [7,4,1]
Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.
Example 2:

Input: root = [1], target = 1, k = 3
Output: []
 

Constraints:

The number of nodes in the tree is in the range [1, 500].
0 <= Node.val <= 500
All the values Node.val are unique.
target is the value of one of the nodes in the tree.
0 <= k <= 1000

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    /*
        Intution / Basic Algorithm

        -Treat the binary tree as an graph and prepare the AdjList also maintain a count of the number of nodes
        -Since it is a un-directed binary connected graph / tree we can apply bfs to compute the distance of all the nodes
            from the source node given
        -return those nodes which are at k distance from the given source node

        For storing the distance we can use the count of nodes computed above for creating the distance and visited vector
    */



    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        /*
            Compute the adjList using the given root node by applying the level order traversal
        */

        vector<vector<int>> adjList(500);

        queue<TreeNode*> q;
        q.push(root);
        int nodeCount=0;
        while(!q.empty())
        {
            
            int count=q.size();
            
            for(int i=0;i<count;i++)
            {
                int current_value=q.front()->val;
                TreeNode* current=q.front();
                //adjList.push_back(current_value);
                q.pop();
                nodeCount++;
                if(current->left!=nullptr)
                {
                   int childNode=current->left->val;
                    adjList[current_value].push_back(childNode);
                    adjList[childNode].push_back(current_value);
                    q.push(current->left);
                }
                if(current->right!=nullptr)
                {
                    int childNode=current->right->val;
                    adjList[current_value].push_back(childNode);
                    adjList[childNode].push_back(current_value);
                    q.push(current->right);
                }
            }

        }

        /*
            Since initilaly we didi'nt knew about the size of the number of nodes we initiliazed the vector with value
            500 which was the max number of nodes given in the constraints
        
        */

        adjList.resize(nodeCount);

        // for(int i=0;i<nodeCount;i++)
        // {
        //     for(int j:adjList[i])
        //     {
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }

        /*
            Now since we have the adjList the the requirement is to calthe distance from the traget node
            we can cal the distance og all the nodes from the targetNode and return those nodes which are at 
            k distance from the source node (targetNode)
        
        */

        
        //cout<<nodeCount<<"The total number of nodes in the graph"<<endl;
        if(nodeCount==1)    return {};

        /*
            This is the based consition thatwe need to check if there is only 1 node in the tree there would 
            no no neighbouring node hence we return a null vector
        
        */

        queue<int> qt;
        qt.push(target->val);
        
        /*
            As basic bfs parctice we maintain a vsisited vector and a distacne vector so that we do not go in infinite
            loop and al have a record of the distance from the root node
        
        */

        vector<int> dist(nodeCount);
        vector<bool> visited(nodeCount);
        visited[target->val]=true;
        dist[target->val]=0;
        while(!qt.empty())
        {
            int current=qt.front();
            qt.pop();
            for(int i:adjList[current])
            {
                
                if(visited[i]==false)
                {
                    dist[i]=dist[current]+1;
                    visited[i]=true;
                    qt.push(i);
                }
                
            }
        }

        //cout<<"Distance vector"<<endl;
        vector<int> ans;
        for(int i=0;i<nodeCount;i++)
        {
            if(dist[i]==k)
            {   
                ans.push_back(i);
            }
        }

        return ans;

        

        













    }
};