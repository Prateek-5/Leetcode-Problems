/*

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
 

Constraints:

1 <= numCourses <= 2000
0 <= prerequisites.length <= 5000
prerequisites[i].length == 2
0 <= ai, bi < numCourses
All the pairs prerequisites[i] are unique.

*/

class Solution {
public:
    /*
        Basic Idea / Intution

        -the basic idea for the follwing proble is to find out the the topological sort of the given graph
        and while finding out the topological sort of the given graph we need to keep a additional counter for the
        number of elements that get added into the queue and after the topological sort is been calculated we need to 
        compare that counter value with the totoal number of vertix and if that number is equal then it means that we 
        can accumodate all the courses asper the question but if its not equal that we have to retunr false

        Implemenation details
            -As we are been privided with the edges we need to create an Adj List
            -Calculate the inDegree of the following graph
            -Calculate the topological sort of the following graph
            -Keep a counter to that gets incremented when ever we make an addition to the queue in the 
                topological queue 
    
    
    */




    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses,0);
        vector<vector<int>> adjList(numCourses);

        for(auto i:prerequisites){
            inDegree[i[0]]++;
            adjList[i[1]].push_back(i[0]);
        }

        queue<int> q;
        for(int i=0;i<numCourses;i++)
        {
            if(inDegree[i]==0){
                q.push(i);
            }
        }
        //the following count variable that keeps atrack of the number of elements in the topological sort
        int count=0;
        while(!q.empty())
        {
            int current=q.front();
            q.pop();
            count++;

            for(int i:adjList[current])
            {
                if(--inDegree[i]==0){
                    q.push(i);
                }
            }
        }

        return count==numCourses;

    }
};