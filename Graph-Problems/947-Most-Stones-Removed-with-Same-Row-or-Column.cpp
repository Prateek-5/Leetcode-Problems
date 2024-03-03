/*
On a 2D plane, we place n stones at some integer coordinate points. Each coordinate point may have at most one stone.

A stone can be removed if it shares either the same row or the same column as another stone that has not been removed.

Given an array stones of length n where stones[i] = [xi, yi] represents the location of the ith stone, return the largest possible number of stones that can be removed.

 

Example 1:

Input: stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
Output: 5
Explanation: One way to remove 5 stones is as follows:
1. Remove stone [2,2] because it shares the same row as [2,1].
2. Remove stone [2,1] because it shares the same column as [0,1].
3. Remove stone [1,2] because it shares the same row as [1,0].
4. Remove stone [1,0] because it shares the same column as [0,0].
5. Remove stone [0,1] because it shares the same row as [0,0].
Stone [0,0] cannot be removed since it does not share a row/column with another stone still on the plane.
Example 2:

Input: stones = [[0,0],[0,2],[1,1],[2,0],[2,2]]
Output: 3
Explanation: One way to make 3 moves is as follows:
1. Remove stone [2,2] because it shares the same row as [2,0].
2. Remove stone [2,0] because it shares the same column as [0,0].
3. Remove stone [0,2] because it shares the same row as [0,0].
Stones [0,0] and [1,1] cannot be removed since they do not share a row/column with another stone still on the plane.
Example 3:

Input: stones = [[0,0]]
Output: 0
Explanation: [0,0] is the only stone on the plane, so you cannot remove it.
 

Constraints:

1 <= stones.length <= 1000
0 <= xi, yi <= 104
No two stones are at the same coordinate point.

*/
class Solution {
public:

    /*
        Intution / Basic Algorithm

        -Basical we have to group the point of similar x or y co-ordinates into a single cluster
        -That can be achieved using the dfs function call as all the point that share the same x or y 
            co-ordinate will be updated in the visited vector in 1 dfs call only and thought that
            we can keep a track by the number of times the dfs function is been called from the main function
            (explicitly) to know how many cluster are there
        -In each cluster 1 point will remain that we are unable to remove that's why total stone - number of cluster
        -Is our answer 
    
    
    */



    void dfs(int source,vector<bool>& visited,vector<vector<int>>& stones)
    {
        visited[source]=true;

        for(int i=0;i<stones.size();i++)
        {
            /*
                Reason and example for traversal
                Example we called for point (0,0)
                The current = 0 (The first point)

                stones[source][0]   --> This denotes 0 (the first value of the pair x-co-ordinate)
                stones[source][1]  --> This denotes 0  (the second value of the pair y-co-ordinate)

                The reason of iterating through the whole stones vector is to find a pair that has the same 
                x value
                or
                y value
                If we find that we again recursive call for that particular index (That particulat point)

            
            */


            if(!visited[i] &&  (stones[source][0]==stones[i][0] || stones[source][1]==stones[i][1]))
            {
                /*
                    The following condition will be true if we have found a point with similar x or y co-ordinates
                    which is yet un-visited
                
                */
                dfs(i,visited,stones);
            }
        }



    }




    int removeStones(vector<vector<int>>& stones) {
        int count=0;
        int n=stones.size();
        vector<bool> visited(n);
        for(int i=0;i<stones.size();i++)
        {
            if(!visited[i])
            {
                dfs(i,visited,stones);
                count++;
            }
        }

        /*
            For each dfs call there would be 1 vertex from the whole cluster of connected components
            that will remain .That's the reason we have kept the count of the number of time the count
            variable is been called and will return totalStone - number of connected cluster(number of time dfs is been called)

        
        */


        return n-count;        
    }
};