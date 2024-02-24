/*
There is a directed graph of n nodes with each node labeled from 0 to n - 1. The graph is represented by a 0-indexed 2D integer array graph where graph[i] is an integer array of nodes adjacent to node i, meaning there is an edge from node i to each node in graph[i].

A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node (or another safe node).

Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.

 

Example 1:

Illustration of graph
Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
Output: [2,4,5,6]
Explanation: The given graph is shown above.
Nodes 5 and 6 are terminal nodes as there are no outgoing edges from either of them.
Every path starting at nodes 2, 4, 5, and 6 all lead to either node 5 or 6.
Example 2:

Input: graph = [[1,2,3,4],[1,2],[3,4],[0,4],[]]
Output: [4]
Explanation:
Only node 4 is a terminal node, and every path starting at node 4 leads to node 4.
 

Constraints:

n == graph.length
1 <= n <= 104
0 <= graph[i].length <= n
0 <= graph[i][j] <= n - 1
graph[i] is sorted in a strictly increasing order.
The graph may contain self-loops.
The number of edges in the graph will be in the range [1, 4 * 104].

*/


class Solution {
public:
    /*
        Basic Intution / Algorithm

        The basic intution for the following proble is to detect if a cycle is present in the graph or not ans at the same 
        point of time we also have to add allthose vertix which are present in those cycle
         
        Implelentation Details
            -Implement a function for cycle detection usinf dfs algorithm 
                -For the very same function we will require 2 vector where one will point
                    -currentVisited all the vector that are been visited in the cuurent dfs cycle
                    -OverallVisited all the vectors that have been visited overall
                -For implementation one thing that is very important is we need to conside the fact once we retrace from
                    any vector we mark its currentVisited as false
                -If a situtation arises where the currentVisited and the overallVisited both are marked as true we will
                 return true in the following condition meaning that there is a cycle

    
    */

    bool isCycle(int source,vector<bool>& currentVisited,vector<bool>& overallVisited,vector<vector<int>>& graph,vector<bool>& presentCycle)
    {
        currentVisited[source]=true;
        overallVisited[source]=true;

        for(int i:graph[source]){
            if(!overallVisited[i] && isCycle(i,currentVisited,overallVisited,graph,presentCycle))
            {   
                /*
                    The follwoing step is also very important as it is responcile for the once the recursive all
                    retrace all the immediate parents of the vertix will be marked as true which will eventually
                    create all the vertix that are present in the cycle to be a part of the follwing vector
                
                */
                return presentCycle[source]=true;
            }
            if(overallVisited[i] && currentVisited[i]){
                return presentCycle[source]=true;
            }
        }
        /*
            this step is very important as we are retracing from this vertix and this will not be a part of
            our current all stack that's why for the current iteration we are moving it to false so that it wount't
            create problem when the same vertix is been visited again in some other iteration of this function all 
            or we can say that in some other cycle
        */
        currentVisited[source]=false;
        return false;
    }





    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<bool> currentVisited(n,false);
        vector<bool> overallVisited(n,false);
        vector<bool> presentCycle(n,false);

        for(int i=0;i<n;i++){
            if(overallVisited[i]==false){
                isCycle(i,currentVisited,overallVisited,graph,presentCycle);
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(presentCycle[i]==false)
            {
                ans.push_back(i);
            }
        }


        return ans;



    }
};