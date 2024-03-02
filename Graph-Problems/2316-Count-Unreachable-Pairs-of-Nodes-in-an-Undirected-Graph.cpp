/*
You are given an integer n. There is an undirected graph with n nodes, numbered from 0 to n - 1. You are given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting nodes ai and bi.

Return the number of pairs of different nodes that are unreachable from each other.

 

Example 1:


Input: n = 3, edges = [[0,1],[0,2],[1,2]]
Output: 0
Explanation: There are no pairs of nodes that are unreachable from each other. Therefore, we return 0.
Example 2:


Input: n = 7, edges = [[0,2],[0,5],[2,4],[1,6],[5,4]]
Output: 14
Explanation: There are 14 pairs of nodes that are unreachable from each other:
[[0,1],[0,3],[0,6],[1,2],[1,3],[1,4],[1,5],[2,3],[2,6],[3,4],[3,5],[3,6],[4,6],[5,6]].
Therefore, we return 14.
 

Constraints:

1 <= n <= 105
0 <= edges.length <= 2 * 105
edges[i].length == 2
0 <= ai, bi < n
ai != bi
There are no repeated edges.


*/
class Solution {
public:

    /*
        Intution / Basic Algorithm
    
        The basic idea for the following problem is we need to calculate the number of cluster and the number of nodes present in them

        For the same we iterate through the same edges and create a union of vertixes if and when required
         
    
    
    
    */


    int findNode(int a,vector<int>& parent)
    {
        if(parent[a]==a)
        {
            return a;
        }
        return parent[a]=findNode(parent[a],parent);
    }

    void unionNode(int a,int b,vector<int>& parent,vector<int>& rank)
    {
        int x=findNode(a,parent);
        int y=findNode(b,parent);

        if(x==y)    return;
        if(rank[x] > rank[y])
        {
            parent[y]=x;
        }
        else if(rank[y] > rank[x])
        {
            parent[x]=y;
        }
        else
        {
            parent[y]=x;
            rank[x]++;
        }

    }



    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> parent(n);
        vector<int> rank(n,0);
        
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }

        for(auto &i:edges)
        {
            int x=i[0];
            int y=i[1];
            if(findNode(x,parent)!=findNode(y,parent))
            {
                unionNode(x,y,parent,rank);
            }
        }

        // for(auto i:parent)
        // {
        //     cout<<i<<" ";
        // }
        cout<<endl;
        map<int, int> componentSizes;
        for (int i = 0; i < n; i++) {
            componentSizes[findNode(i, parent)]++;
        }

        // for(auto i:parent)
        // {
        //     cout<<i<<" ";
        // }
        /*
            Before:
            5 5 5 5 5 5 4 10 9 5 5
            After: 
            5 5 5 5 5 5 5 5 5 5 5 
        
        */
        /*
            This follwing is the main logic of the program
            here we are ireating throug all the vertex and then finding out the and storing the parent and it's assiciated nodes
            like how many nodes are there in the respective parent node (number of nodes in the cluster)

            Once we have the number we multiply if by how many nondes are not there in the clustor hence we arrive at a number 
            which indicated the number of pairs that are unreachable for all the nodes if this cluster
            We perform the same for all the cluster and the from the final result we divide it by 2

            because ex:(1,2) and (2,1) bpth got addded but logically htey are a single pair

            that's why we divide the total result by 2
        
        
        */
        long long result = 0;
        for (const auto& kv : componentSizes) {
            int size = kv.second;
            result += static_cast<long long>(size) * (n - size);
        }

        return result / 2; // Divided by 2 to avoid double counting



    }
};