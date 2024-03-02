/*
There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a network where connections[i] = [ai, bi] represents a connection between computers ai and bi. Any computer can reach any other computer directly or indirectly through the network.

You are given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected.

Return the minimum number of times you need to do this in order to make all the computers connected. If it is not possible, return -1.

 

Example 1:


Input: n = 4, connections = [[0,1],[0,2],[1,2]]
Output: 1
Explanation: Remove cable between computer 1 and 2 and place between computers 1 and 3.
Example 2:


Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]
Output: 2
Example 3:

Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2]]
Output: -1
Explanation: There are not enough cables.
 

Constraints:

1 <= n <= 105
1 <= connections.length <= min(n * (n - 1) / 2, 105)
connections[i].length == 2
0 <= ai, bi < n
ai != bi
There are no repeated connections.
No two computers are connected by more than one cable.

*/

class Solution {
public:
    /*
        Basic Intution /  Algorithm

        -In important point to note for solving the following question that we required at least n-1 number of edges
            to join n nodes(min spanning tree)
        -Also an imporatant base case is associated with this if the numebr of connection given are less than n-1 then we straight away
            return -1 as then it is not possible to connected those components with the min connection 
        -Now the given node we will iterate through the given edges and the then basicalyy try to find out how any disconnected 
         components do we have 
        -Note once we call the union that means that we have connected 2 disconnected components into 1 so we can reduce the 
            count of disconnected components by 1
        -Also it is very important to node that we call the union operation only for those connection where the twi verteces involved a
            are of different parent if they are of same parent then no need to call the union and it is a waste of computation and out
            disconnected component is also liked along wiht the union function call
        -After we have iterated throught all the connection we can check how many disconnected components are there initially that value 
            should be initialized to n(number of nodes) 
        -After we have the number of disconnected components we can return disconnectedComponents -1 as the answer
        -Because the questions is asking how many operation we require to make the Network connected that is we require these 
            extra number of connection to make the network connected 
    
    
    */



    vector<int> parent;
    vector<int> rank;

    int findNode(int a,vector<int>& parent)
    {
        if(a==parent[a])
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



    int makeConnected(int n, vector<vector<int>>& connections) {
        parent.resize(n);
        rank.resize(n);
        int extraConnection=0;
        int initialComponent=n;
        if(connections.size() < n-1)    return -1;
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
            rank[i]=0;
        }


        for(auto &i:connections)
        {
            int x=i[0];
            int y=i[1];
            if(findNode(x,parent)==findNode(y,parent))
            {
                extraConnection++;
            }
            else
            {
                initialComponent--;
                unionNode(x,y,parent,rank);
            }
        }
        
        int edgesRequired=initialComponent-1;

        


        

        return edgesRequired;





    }
};