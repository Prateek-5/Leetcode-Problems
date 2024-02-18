/*
Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell.

Example 1:

Input:
N = 4
m[][] = {{1, 0, 0, 0},
         {1, 1, 0, 1}, 
         {1, 1, 0, 0},
         {0, 1, 1, 1}}
Output:
DDRDRR DRDDRR
Explanation:
The rat can reach the destination at 
(3, 3) from (0, 0) by two paths - DRDDRR 
and DDRDRR, when printed in sorted order 
we get DDRDRR DRDDRR.
Example 2:
Input:
N = 2
m[][] = {{1, 0},
         {1, 0}}
Output:
-1
Explanation:
No path exists and destination cell is 
blocked.
Your Task:  
You don't need to read input or print anything. Complete the function printPath() which takes N and 2D array m[ ][ ] as input parameters and returns the list of paths in lexicographically increasing order. 
Note: In case of no path, return an empty list. The driver will output "-1" automatically.

Expected Time Complexity: O((3N^2)).
Expected Auxiliary Space: O(L * X), L = length of the path, X = number of paths.

Constraints:
2 ≤ N ≤ 5
0 ≤ m[i][j] ≤ 1

*/
// User function template for C++

class Solution{
    public:
    
    void solve(int x,int y,string currstr,vector<vector<int>>& visited,vector<string>& ans,vector<vector<int>>& m,int n){
        
        //the following is the base case where we decice we have arrived at the solution
        if(x==n-1 && y==n-1){
            ans.push_back(currstr);
            return;
        }
        
        /*
            
            To get the string in lexiographical order we need to maintain the following order
            -down
            -left
            -right
            -upward
            
        */
        
        //down
        
        
        if(x+1<n && m[x+1][y]==1 && visited[x+1][y]==0){ //the conditional check for the array
            visited[x][y]=1; //mark the current node as visited
            solve(x+1,y,currstr+'D',visited,ans,m,n); //call the recursive function with the directionwe want to naviguate
            visited[x][y]=0;//the traditional backtarcking approch where we mark the vector as not-visited
        }
        
        
        //left
        
        if(y-1>=0 && m[x][y-1]==1 && visited[x][y-1]==0){
            visited[x][y]=1;
            solve(x,y-1,currstr+'L',visited,ans,m,n);
            visited[x][y]=0;
        }
        
        
        
        
        
        //right
        
        if(y+1<n && m[x][y+1]==1 && visited[x][y+1]==0){
            visited[x][y]=1;
            solve(x,y+1,currstr+'R',visited,ans,m,n);
            visited[x][y]=0;
        }
        
        //upwards
        if(x-1>=0 && m[x-1][y]==1 && visited[x-1][y]==0){
            visited[x][y]=1;
            solve(x-1,y,currstr+'U',visited,ans,m,n);
            visited[x][y]=0;
        }
        
        
        
        
        
    }
    
    /*
        
        The following is also a backtarcking problem where we need to return the string in lexiographilcal order the path
        that would start from (0,0) and end until (n-1,n-1).
        
        There are few concerns that we need to take care while naviguating 
            -we cannot got out of bound
            -we can only tarvell if we have 1
            -we cannot visit the same node twice(that's why we need to maintain a visited vector)
            
    
    */
    
    
    
    
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans; //the following will store the ans vector
        string currstr="";//it will store the current string iteration
        vector<vector<int>> visited(n,vector<int>(n,0)); //we have created the following vector to store the visited array
        
        if(m[0][0]==1){
            solve(0,0,currstr,visited,ans,m,n);
        }
        
        return ans;
        
        
    }
};
