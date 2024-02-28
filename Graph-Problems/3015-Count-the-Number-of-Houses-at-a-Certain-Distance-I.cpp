/*
You are given three positive integers n, x, and y.

In a city, there exist houses numbered 1 to n connected by n streets. There is a street connecting the house numbered i with the house numbered i + 1 for all 1 <= i <= n - 1 . An additional street connects the house numbered x with the house numbered y.

For each k, such that 1 <= k <= n, you need to find the number of pairs of houses (house1, house2) such that the minimum number of streets that need to be traveled to reach house2 from house1 is k.

Return a 1-indexed array result of length n where result[k] represents the total number of pairs of houses such that the minimum streets required to reach one house from the other is k.

Note that x and y can be equal.

 

Example 1:


Input: n = 3, x = 1, y = 3
Output: [6,0,0]
Explanation: Let's look at each pair of houses:
- For the pair (1, 2), we can go from house 1 to house 2 directly.
- For the pair (2, 1), we can go from house 2 to house 1 directly.
- For the pair (1, 3), we can go from house 1 to house 3 directly.
- For the pair (3, 1), we can go from house 3 to house 1 directly.
- For the pair (2, 3), we can go from house 2 to house 3 directly.
- For the pair (3, 2), we can go from house 3 to house 2 directly.
Example 2:


Input: n = 5, x = 2, y = 4
Output: [10,8,2,0,0]
Explanation: For each distance k the pairs are:
- For k == 1, the pairs are (1, 2), (2, 1), (2, 3), (3, 2), (2, 4), (4, 2), (3, 4), (4, 3), (4, 5), and (5, 4).
- For k == 2, the pairs are (1, 3), (3, 1), (1, 4), (4, 1), (2, 5), (5, 2), (3, 5), and (5, 3).
- For k == 3, the pairs are (1, 5), and (5, 1).
- For k == 4 and k == 5, there are no pairs.
Example 3:


Input: n = 4, x = 1, y = 1
Output: [6,4,2,0]
Explanation: For each distance k the pairs are:
- For k == 1, the pairs are (1, 2), (2, 1), (2, 3), (3, 2), (3, 4), and (4, 3).
- For k == 2, the pairs are (1, 3), (3, 1), (2, 4), and (4, 2).
- For k == 3, the pairs are (1, 4), and (4, 1).
- For k == 4, there are no pairs.
 

Constraints:

2 <= n <= 100
1 <= x, y <= n

*/
class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        vector<vector<int>> grid(n+1,vector<int> (n+1,1e8));

        /*
            Based on the logic that the a
            There is a street connecting the house numbered i with the house numbered i + 1 for all 1 <= i <= n - 1 .
        
        */
        
        for(int j=1;j<n;j++)
        {
            grid[j][j+1]=1;
            grid[j+1][j]=1;
        }
        /*
            An additional street connects the house numbered x with the house numbered y.
            To accummodate the addition street 
        */

        grid[x][y]=1;
        grid[y][x]=1;

        
        /*
            Now since we have the min required adjList we will apply the Floyd warshall algorithm to compute the min
            distance between all the pair of the vertixes 
        */
        /*
            Since we have initialized the the grid with 1e8 the min distance and then we are optimizing it we have to make sure
            that we explicitly mention the the grid value like
                grid[1][1] , grid[2][2] , grid[3][3] , grid[4][4]
            As 0 explicitly the min value computed by the floyd Warshall algorithm will never be equal to 0
            But pracitically it has to be zero for calculation prespective
        
        */
        /*
            The implementation of the Floyf Warshall algo as usual since  the nodes are starting from 1 we have started the 
            loop from 1 and not from 0
        
        */
        for(int via=1;via<=n;via++)
        {
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    if(i==j)    grid[i][j]=0;
                    grid[i][j]=min(grid[i][j],grid[i][via]+grid[via][j]);
                }
            }
        }

        // for(int i=1;i<=n;i++)
        // {
        //     for(int j=1;j<=n;j++)
        //     {
        //         cout<<grid[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        /*
            The result vector is sort of a hashmap in the below use case where we store the distacne and their 
            frequency in the grid

            Since it is a 1-indexed vectore 
                Suppose the distance is 1 we store it at the 0th index and if the distance is 2 we store it
                at the 1st index asn so on
        */
        vector<int> result(n);

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                /*
                    For each k, such that 1 <= k <= n, you need to find the number of pairs of houses
                    Becaus eof the following point we have exculded the 0 distance from out result calculation
                
                */
                if(i != j) {
                    int val = grid[i][j];
                    result[val-1]++;
                }

            }
        }
        
        return result;









    }
};