/*
You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.

A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

Return the minimum effort required to travel from the top-left cell to the bottom-right cell.

 

Example 1:



Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
Output: 2
Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.
Example 2:



Input: heights = [[1,2,3],[3,8,4],[5,3,5]]
Output: 1
Explanation: The route of [1,2,3,4,5] has a maximum absolute difference of 1 in consecutive cells, which is better than route [1,3,5,3,5].
Example 3:


Input: heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
Output: 0
Explanation: This route does not require any effort.
 

Constraints:

rows == heights.length
columns == heights[i].length
1 <= rows, columns <= 100
1 <= heights[i][j] <= 106

*/

class Solution {
public:
    /*
        Intution / Basic Algorithm

        -We have to calculate the min effort that mean we need to minimize the abs(height[x2][y2] - height[x1][y1])

        minHeap pair<int,pair<int,int>>

        vector<vector<int>> dist
        vector<vector<bool>> visited

        Dijkstra Algorithm 
            The factor that we are trying to minimize is the min differnce(of the max known differnce of multiple path)

            Ex: If suppose two path lead to (m-1,n-1)
                    path1->Has the max_difference   2
                    path2->Has the max_differnce    3
                We over here are suppose to minimize the max_differnce if differnct path


    
    */

    typedef pair<int,pair<int,int>> pt;
    /*
        This is the helper function to determine we do not go out of bound in the matrix
    */
    bool isValid(int x,int y,vector<vector<int>>& heights)
    {
        if(x<0 || x>=heights.size() || y<0 || y>=heights[0].size())
        {
            return false;
        }
        return true;
    }



    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int m=heights.size();
        int n=heights[0].size();
        
        vector<vector<int>> dist(m,vector<int> (n,INT_MAX));
        
        /*
            In the priority_queue we store the {differece,{x,y}}
        */
        priority_queue<pt,vector<pt>,greater<pt>> pq;
        if(m==1 && n==1)    return 0;

        /*
            Few important parameter that need to initialized in order to proceed
                initial difference if the source [0][0] is 0
                So we push it into the priority_queue
                initialize the initila distance in the dist vector as 0
        */

        pq.push({0,{0,0}});
        dist[0][0]=0;
        while(!pq.empty())
        {   
            /*
                featch out the x,y and weight co-ordinated from the priority queue
            */

            int x=pq.top().second.first;
            int y=pq.top().second.second;
            int weight=pq.top().first;
            pq.pop();
            /*
                Iterate throught all the possible valus form the current co-ordinates
            
            */
            int x1[]={0,-1,0,1};
            int y1[]={1,0,-1,0};

            for(int i=0;i<4;i++)
            {
                int x_cord=x+x1[i];
                int y_cord=y+y1[i];

                if(isValid(x_cord,y_cord,heights))
                {
                    /*
                        Why are we computing the max_difference 
                            -The current_ongoing_difference -->weight
                            -the current_freshly_computed_difference -> abs(heights[x_cord][y_cord]-heights[x][y])
                        
                        This is because the min effort in the path is the maxDifference in the path that's why
                        we first compute the max_difference in the path and then compare it with if the istance stored
                        in the distance vector is min or not for distance vector we always consider the min distance
                    
                    */
                    

                    int max_diff=max(weight,abs(heights[x_cord][y_cord]-heights[x][y]));
                    /*
                        We always want the min value in the dist vector but for computing we always consider the max value
                        that is the max differnce in the path
                    
                    
                    */
                    if(dist[x_cord][y_cord] > max_diff)
                    {
                        dist[x_cord][y_cord]=max_diff;
                        pq.push({dist[x_cord][y_cord],{x_cord,y_cord}});

                    }
                }

            }


          



        }
        //   for(auto i:dist)
        //     {
        //         for(auto j:i)
        //         {
        //             cout<<j<<" ";
        //         }
        //         cout<<endl;
        //     }


            return dist[m-1][n-1];


    }
};