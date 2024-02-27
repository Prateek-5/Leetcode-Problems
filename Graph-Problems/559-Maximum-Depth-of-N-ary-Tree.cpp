/*
Given a n-ary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value (See examples).

 

Example 1:



Input: root = [1,null,3,2,4,null,5,6]
Output: 3
Example 2:



Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
Output: 5
 

Constraints:

The total number of nodes is in the range [0, 104].
The depth of the n-ary tree is less than or equal to 1000.

*/


/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    /*
        Basic Intution / Algorithm
        
            Consider the n-array tree as a directed graph with unit distance
            Implement the bfs based algorith to calculate the distace from the source to all the nodes
            as it will always be a connected graph throught 1 bfs based traversal we can iterate throught the 
            whole tree

        -we implement the bfs based algotith to calculate the distance
        -store the distance in the hastmap
        -return the max value in the hashmap +1

        As in the bfs based traversal we are given up with the adjList here we are provided up with the children vector
        Since the number of nodes are not defined we cannot initialized a distance array and store the result in it we have
        used the hash map to store the distance and featch out the distance
         and remember the mp.find() method return a pointer so make sure to store it in a  auto variable and then access the 
         mp recored like if will return something like 
            mp.find(root)       returns {rootNode,distance}
        so inorder to access the distance we need to mention like it->second
        Since we are calculating the distacne of the farthest  node from the root we need to make sure we add 1 to the result 
        so that we can include the root node also in the calculation

    
    */



    int maxDepth(Node* root) {
        if(root==nullptr)       return 0;
        queue<Node*> q;
        q.push(root);
        map<Node*,int> mp;
        mp.insert({root,0});
       

        while(!q.empty())
        {
            Node* current=q.front();
            q.pop();
            int count=current->children.size();
            for(int i=0;i<count;i++)
            {
                Node* child_node=current->children[i];
                auto it=mp.find(current);
                int distance=it->second + 1;
                mp.insert({child_node,distance});
                q.push(child_node);
            }

        }
        int maxi=INT_MIN;
        for(auto i: mp)
        {
            //cout<<i.first->val<<" "<<i.second<<endl;
            maxi=max(maxi,i.second);
        }

        return maxi+1;


    }
};

/*
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
/*

also a possible solution as we are performing the level order traversal we can return the levs we iterated and that can be our answer 

class Solution {
public:
    int maxDepth(Node* root) {
        if(root==NULL)
        {
            return 0;
        }
        int ans=0;
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                Node* curr=q.front();
                q.pop();
                for(auto it: curr->children)
                {
                    q.push(it);
                }
            }
            ans++;
        }

        return ans;
    }
};


*/