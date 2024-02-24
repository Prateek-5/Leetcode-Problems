/*
In a town, there are n people labeled from 1 to n. There is a rumor that one of these people is secretly the town judge.

If the town judge exists, then:

The town judge trusts nobody.
Everybody (except for the town judge) trusts the town judge.
There is exactly one person that satisfies properties 1 and 2.
You are given an array trust where trust[i] = [ai, bi] representing that the person labeled ai trusts the person labeled bi. If a trust relationship does not exist in trust array, then such a trust relationship does not exist.

Return the label of the town judge if the town judge exists and can be identified, or return -1 otherwise.

 

Example 1:

Input: n = 2, trust = [[1,2]]
Output: 2
Example 2:

Input: n = 3, trust = [[1,3],[2,3]]
Output: 3
Example 3:

Input: n = 3, trust = [[1,3],[2,3],[3,1]]
Output: -1
 

Constraints:

1 <= n <= 1000
0 <= trust.length <= 104
trust[i].length == 2
All the pairs of trust are unique.
ai != bi
1 <= ai, bi <= n
*/

class Solution {
public:
    /*
        The basic idea for the following question is that we need to calculate the in-degree and out-degree
        for all the vertixes given in the trust arre 

        -The condition that we are searching is that 
            -In-degree of a particular vertix is N 
            -And on the same time the Out-Degree of that particular vertix is 0
        For solving the following question we wouch require 2 vertex 
            -In-Degree
            -Out-Degree
        After storing the resut in these 2 vector we will iterate through these 2 vectors and search for the
        above condition

    
    
    */



    int findJudge(int n, vector<vector<int>>& trust) {
        
        vector<int> inDegree(n+1,0);
        vector<int> outDegree(n+1,0);

        /*
            Storing the inDegree and outDegree in the respective vector
                inDegree- An edge comes towards the vector
                outDegree- An edge comes out of the vertex
            
        
        */


        for(auto i:trust)
        {
            outDegree[i[0]]++;
            inDegree[i[1]]++;
        }
        
        /*
            Iterating throught the inDegree and OutDegree vertex to see if we have a condition where
            and vertix has 0 outDegree vetex and n-1 inDegree vertix 
        
        */


        for(int i=1;i<=n;i++)
        {
            if(outDegree[i]==0 && inDegree[i]==n-1)
            {
                return i;
            }
        }

        return -1;






    }
};