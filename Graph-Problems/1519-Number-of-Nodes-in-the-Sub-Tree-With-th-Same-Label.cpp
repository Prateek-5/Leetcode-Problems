/*
You are given a tree (i.e. a connected, undirected graph that has no cycles) consisting of n nodes numbered from 0 to n - 1 and exactly n - 1 edges. The root of the tree is the node 0, and each node of the tree has a label which is a lower-case character given in the string labels (i.e. The node with the number i has the label labels[i]).

The edges array is given on the form edges[i] = [ai, bi], which means there is an edge between nodes ai and bi in the tree.

Return an array of size n where ans[i] is the number of nodes in the subtree of the ith node which have the same label as node i.

A subtree of a tree T is the tree consisting of a node in T and all of its descendant nodes.

 

Example 1:


Input: n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], labels = "abaedcd"
Output: [2,1,1,1,1,1,1]
Explanation: Node 0 has label 'a' and its sub-tree has node 2 with label 'a' as well, thus the answer is 2. Notice that any node is part of its sub-tree.
Node 1 has a label 'b'. The sub-tree of node 1 contains nodes 1,4 and 5, as nodes 4 and 5 have different labels than node 1, the answer is just 1 (the node itself).
Example 2:


Input: n = 4, edges = [[0,1],[1,2],[0,3]], labels = "bbbb"
Output: [4,2,1,1]
Explanation: The sub-tree of node 2 contains only node 2, so the answer is 1.
The sub-tree of node 3 contains only node 3, so the answer is 1.
The sub-tree of node 1 contains nodes 1 and 2, both have label 'b', thus the answer is 2.
The sub-tree of node 0 contains nodes 0, 1, 2 and 3, all with label 'b', thus the answer is 4.
Example 3:


Input: n = 5, edges = [[0,1],[0,2],[1,3],[0,4]], labels = "aabab"
Output: [3,2,1,1,1]
 

Constraints:

1 <= n <= 105
edges.length == n - 1
edges[i].length == 2
0 <= ai, bi < n
ai != bi
labels.length == n
labels is consisting of only of lowercase English letters.

*/

class Solution {
public:
    /*
        Intution / Basic Algorithm

        -The basic algorithm for the following problem is we need to capture the frequency of the label 
            -before and after calling the dfs for a particular node
            -The refrence of the labels are been maintained in a count array of size 26 as the labels are restricted to lower case alphabates only
            -Also we need to maintain a seperate vector indexed to the node number which store the frequence difference of the labels the node
                stores
            -Initially the count and result array need to be initialized to zero 
            -Do a dry run a particulat test cases and you will be able to find out the logic of the following case
            -Pre-requist we need to create a bi-directional graph for the given set of edges 
            -We need to send a additional parameter for us to determine we do not end up in a self endless loop
    
    
    
    
    
    */
    int dfs(int source,int parent,vector<int>& result,vector<int>& count,vector<vector<int>>& adjList,string& labels)
    {

        int currentLable=labels[source]-'a';
        
        int initialCount=count[currentLable];
        count[currentLable]++;
        for(int &i:adjList[source])
        {
            if(i==parent)   continue;
            dfs(i,source,result,count,adjList,labels);
        }
        int updatedCount=count[currentLable];

        int resultCount=updatedCount-initialCount;
        result[source]=resultCount;
        return resultCount;

    }



    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        
        
        vector<vector<int>> adjList(n);
        for(auto &i:edges)
        {
            int u=i[0];
            int v=i[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);        
        }

        vector<int> result(n,0);
        vector<int> count(26,0);

        dfs(0,-1,result,count,adjList,labels);

        return result;



    }
};
/* A not so optimal approch*/
class Solution {
public:
    /*
        Intution / Basic Algorithm
        
        - We need to impleamrn dfs based solution for the following problem
        -Each and every node in the tree will create a new vector of the frequency of it's labels
        -Once the node has updated it's lable it will call for the child node for their respective vectors
        -Once we have received the vectors from the child node we will run a for loop to iterate over the 
            over the child vector and update the valus in the current node's vector if there are any updates
        -Once we are done with the same a have a resultant vector we will update the frequence value of the current
            lable at the index of the node
        -and at then end returnt he result as answer 




    
    */

    vector<int> dfs(int source,int parent,vector<vector<int>>&adjList,string& labels,vector<int>& result)
    {

        vector<int> myCount(26,0);
        //update the count of the self lable
        myCount[labels[source]-'a']=1;

        for(auto &i:adjList[source])
        {
            if(i==parent)   continue;
            vector<int> childCount(26,0);
            childCount=dfs(i,source,adjList,labels,result);

            for(int i=0;i<26;i++)
            {
                myCount[i]+=childCount[i];
            }

            
        }
        result[source]=myCount[labels[source]-'a'];
        return myCount;



    }






    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> adjList(n);

        for(auto &i:edges)
        {
            int u=i[0];
            int v=i[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        vector<int> result(n,0);
        dfs(0,-1,adjList,labels,result);
        return result;

    }
};