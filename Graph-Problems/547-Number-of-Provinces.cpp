/*
There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.

 

Example 1:


Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2
Example 2:


Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3
 

Constraints:

1 <= n <= 200
n == isConnected.length
n == isConnected[i].length
isConnected[i][j] is 1 or 0.
isConnected[i][i] == 1
isConnected[i][j] == isConnected[j][i]

*/

class Solution {
public:
    /*
        Sudo Code / Algorithm

        -Here we need to return the number of provinces or we can say the number of disconnected components
        -The approch will be similar to number of island where we will be calling the dfs function and keeping a track of the
             number of times the following functon is been called
        -Since we are not provided up with a matrix where we can make changes in-place we need  an additional visited vector
        -The visited vector will keep a track of the nodes that we have already visited so that we do not end up in a infinite loop
        -The function required for the following problem
            -dfs function
    
    */

    void dfs(int source,vector<int>& isVisited,vector<vector<int>>& isConnected){
        /*
            In the folowing step we make the vertex for whichh the dfs fucntion is been called as visited
        */
        isVisited[source]=1;
        
        /*
            Now we will iterate throughth the the isConnected[source] which means
                Ex- if the the source is 0 in the below loop we will iterate throught the 0th row of the matrxi
            And during the following traversal if we find out that any of the virtext is connected
                -that is isConnected[source][i]==1 (it means the vertex is connecte to the folliwng vertix)
                -isVisited[i]   the connected vertix is not been visited
            -We call the recursive dfs fucntion for that particular vertix and then it eventually gets marked as visited
            -Once the call  stack return for the fillowing fucntion then if any other vertix is present in the soyrce row then we repete
                the same step for that also
            -For the vertix that are not connected to the vurrent vertix for those we have to initialted a new recursive call with
                new parameter 
            -Note since we are passing th isVisited vectr by reference we are making in-place modification   
            -the same data will be reflected in the loop of the mainfunction and we willlavid fduplicate recursive called
        */

        for(int i=0;i<isConnected[source].size();i++){
            if(isConnected[source][i]==1 && isVisited[i]==0){
                dfs(i,isVisited,isConnected);
            }
        }
    }




    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> isVisited(n,0);
        int count=0;
        for(int i=0;i<n;i++){
            if(isVisited[i]==0){
                count++;
                dfs(i,isVisited,isConnected);
            }
        }
        return count;

    }
};