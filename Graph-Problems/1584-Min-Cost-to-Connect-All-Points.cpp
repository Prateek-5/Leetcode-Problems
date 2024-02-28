/*
You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].

The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.

Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.

 

Example 1:


Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
Output: 20
Explanation: 

We can connect the points as shown above to get the minimum cost of 20.
Notice that there is a unique path between every pair of points.
Example 2:

Input: points = [[3,12],[-2,5],[-4,1]]
Output: 18
 

Constraints:

1 <= points.length <= 1000
-106 <= xi, yi <= 106
All pairs (xi, yi) are distinct.

*/
class Solution {
    /*
        Intution / Basic Algorithm

        Since the follwing question is an implementation of the Prims Algorithm to calculate the minimum spanning tree
        Since we are only concerned with the min cost so we can tree alll the poinst as vertex and the 
            Manhattan distance as the edge o=to connect those two points
        The use of points co-ordinated is to just calculate the distance and after that we can prepare am
        adjList and throught that adjList we can implement the primes algorithm 
    
    
    */

public:

    typedef pair<int,int> pt;

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<vector<double>> matrix(n,vector<double> (n,INT_MAX));

        for(int i=0;i<n;i++)
        {   
            //cout<<"Parent Node"<<points[i][0]<<" "<<points[i][1]<<endl;
            int x1=points[i][0];
            int y1=points[i][1];

            for(int j=0;j<n;j++)
            {
                //cout<<points[j][0]<<" "<<points[j][1]<<endl;
                int x2=points[j][0];
                int y2=points[j][1];
                /*
                The cost of connecting two points [xi, yi] and [xj, yj] 
                is the manhattan distance between them: |xi - xj| + |yi - yj|, 
                where |val| denotes the absolute value of val.
                */

                matrix[i][j]=abs(x1-x2) + abs(y1-y2);

            }
            
        }


        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<n;j++)
        //     {
        //         cout<<matrix[i][j]<<"        ";
        //     }
        //     cout<<endl;
        // }

        priority_queue<pt,vector<pt>,greater<pt>> pq;
        vector<bool> visited(n,false);
        int sum=0;
        /*
            priority_queue Schema
                <distance,vertex>
            Initialal value
                {0,0} -->Sice there is no cost to include the first point        
        
        */

        pq.push({0,0});
        int count=0;
        while(!pq.empty())
        {
            int cost=pq.top().first;
            int currentNode=pq.top().second;
            //cout<<"Cost"<<cost<<endl;
            pq.pop();
            if(visited[currentNode]==true)      continue;
            count++;
            sum+=cost;
            visited[currentNode]=true;
            for(int v=0;v<n;v++)
            {   /*
                    Discover all the vertex which are not yet part of the mst
                    and add the weight(the cost of edge) and node in the payload 
                    The cost is basicallly stored in the martix 
                */

                if(visited[v]==false)
                {
                    int w=matrix[currentNode][v];
                    pq.push({w,v});

                }
            }

        }

        cout<<count-1;
        return sum;





    }
};