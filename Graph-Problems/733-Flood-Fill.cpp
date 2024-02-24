/*
An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.

You are also given three integers sr, sc, and color. You should perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with color.

Return the modified image after performing the flood fill.

 

Example 1:


Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation: From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected to the starting pixel.
Example 2:

Input: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, color = 0
Output: [[0,0,0],[0,0,0]]
Explanation: The starting pixel is already colored 0, so no changes are made to the image.
 

Constraints:

m == image.length
n == image[i].length
1 <= m, n <= 50
0 <= image[i][j], color < 216
0 <= sr < m
0 <= sc < n

*/

class Solution {
public:
    /*
        Basic Intution /Algorithm
            -We are given up with the sire indexex {sr,sc} and we have to call a dfs function for the following co-ordinates
            -In the dfs fucntion we have to update the visited co-ordinates as the color given in the function
                input parameter
            -We have to make the the modification in-place in the image matrix and return it make sure ot pass it by reference
            -we would require a helper isVlaid function for the dfs fucntion so that we do not go out of bound 
    */

    bool isValid(int x,int y,int& initialColor,vector<vector<int>>& image)
    {
        if(x<0 || x>=image.size() || y<0 || y>=image[0].size() || image[x][y]!=initialColor){
            return false;
        }
        return true;
    }

    void dfs(int x,int y,vector<vector<int>>& image,int& color,int& initialColor)
    {
            image[x][y]=color;
            int x1[]={0,-1,0,1};
            int y1[]={1,0,-1,0};
            for(int i=0;i<4;i++)
            {
                int x_cord=x+x1[i];
                int y_cord=y+y1[i];
                if(isValid(x_cord,y_cord,initialColor,image)==true)
                {
                    dfs(x_cord,y_cord,image,color,initialColor);
                }
            }
    }




    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initialColor=image[sr][sc];
        /*
            Very imparotant condition for the code to stop goiing into an endless loop
        */
        if(initialColor==color)     return image;
        dfs(sr,sc,image,color,initialColor);
        return image;

    }
};