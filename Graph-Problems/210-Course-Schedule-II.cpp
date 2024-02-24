/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].
Example 2:

Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
Output: [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].
Example 3:

Input: numCourses = 1, prerequisites = []
Output: [0]
 

Constraints:

1 <= numCourses <= 2000
0 <= prerequisites.length <= numCourses * (numCourses - 1)
prerequisites[i].length == 2
0 <= ai, bi < numCourses
ai != bi
All the pairs [ai, bi] are distinct.
*/

class Solution {
public:
    /*
        Basic Intution / Algorithm 
        -For solving the particular question we need to calculate the inOrder of the vertix and then calculate the
            topological sort of that particular vertix 
        -While caluclatin gthe topological sort if while poping out the element from the queue we will keep an array 
            if the array size is equal ot the number of vertix then we would return the vector else we have to return an
            empty vector as specified by the question
        
    
    
    */



    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> inDegree(numCourses,0);
        vector<vector<int>> adjList(numCourses);

        /*
            Below we are caluclating the inDegree and preparing the adjList for the given data
        */

        for(auto i:prerequisites){
            inDegree[i[0]]++;
            adjList[i[1]].push_back(i[0]);
        }
        deque<int> q;
        /*
            We are pushing those vertix whose inDegree is zero because those need to be added explicitly as
            there is no edge going out from those vertix
        
        */
        for(int i=0;i<numCourses;i++)
        {
            if(inDegree[i]==0)
            {
                q.push_back(i);
            }
        }
        /*
            The followinf is the ans vector that keep a track of the order of vertixes in the topological sort and
            also as per the question if the elements in the topological sort is not equal ot the numCOurses then we need to 
            retun an empty array fo that we can use the size of the vector
        
        */

        vector<int> ans;

        while(!q.empty())
        {
            int current=q.front();
            q.pop_front();
            ans.push_back(current);
            for(int i:adjList[current])
            {
                if(--inDegree[i]==0){
                    q.push_back(i);
                }
            }
        }
        if(ans.size()!=numCourses)      return {};
        return ans;




    }
};