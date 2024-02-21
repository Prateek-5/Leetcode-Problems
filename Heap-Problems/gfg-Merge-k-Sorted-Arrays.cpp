/*
Given K sorted arrays arranged in the form of a matrix of size K*K. The task is to merge them into one sorted array.
Example 1:

Input:
K = 3
arr[][] = {{1,2,3},{4,5,6},{7,8,9}}
Output: 1 2 3 4 5 6 7 8 9
Explanation:Above test case has 3 sorted
arrays of size 3, 3, 3
arr[][] = [[1, 2, 3],[4, 5, 6], 
[7, 8, 9]]
The merged list will be 
[1, 2, 3, 4, 5, 6, 7, 8, 9].
Example 2:

Input:
K = 4
arr[][]={{1,2,3,4},{2,2,3,4},
         {5,5,6,6},{7,8,9,9}}
Output:
1 2 2 2 3 3 4 4 5 5 6 6 7 8 9 9 
Explanation: Above test case has 4 sorted
arrays of size 4, 4, 4, 4
arr[][] = [[1, 2, 2, 2], [3, 3, 4, 4],
[5, 5, 6, 6], [7, 8, 9, 9 ]]
The merged list will be 
[1, 2, 2, 2, 3, 3, 4, 4, 5, 5, 
6, 6, 7, 8, 9, 9].
Your Task:
You do not need to read input or print anything. Your task is to complete mergeKArrays() function which takes 2 arguments, an arr[K][K] 2D Matrix containing K sorted arrays and an integer K denoting the number of sorted arrays, as input and returns the merged sorted array ( as a pointer to the merged sorted arrays in cpp, as an ArrayList in java, and list in python)

Expected Time Complexity: O(K2*Log(K))
Expected Auxiliary Space: O(K2)

Constraints:
1 <= K <= 100

*/

class Solution
{
    public:
    //Function to merge k sorted arrays.
    
    /*
        The following is the syntax of the custom data type
            We have initialized 3 data members
            To initialized them using constructor we need 
                data d(value,array_position,array_index)
            Since the priority_queue is been initialized by the data datatype
            we need to push pq.push(d)
    
    */
    
    class data{
        public:
        
        int element,ap,ai;
        data(int value,int array_position,int array_index){
            element=value;
            ap=array_position;
            ai=array_index;
        }
    };
    
    /*
        The following is the syntex is of a custom comperator function where
        we pass the data datatype and based on the element data member we return
        true or false.
        
        We can also tune the following fucntion to return according to the some other
        data type
    
    */
    
    struct myComp{
        
        bool operator()(data& d1,data& d2){
            return d1.element>d2.element;
        }
        
    };
    
    
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
    /*
        Sudo code algorithm
        -create a custom data type with the following
            -int data
            -int ap (array position)
            -int ai (array index)
        -For the first K arrays insert their first element
        -Initiate a while loop for !pq.empty() (while the priority queue is empty)
        -Inside the loop Extract min store the value parameter in the array
        -Based on the ap and ai we have got hold of insert the next element for the array if it exist
        -condition check if(ai+1 < ap.size())
    */
    
    priority_queue<data,vector<data>,myComp> pq;
    vector<int> ans;
    
    for(int i=0;i<K;i++)
    {
        data d(arr[i][0],i,0);
        pq.push(d);
    }
    
    while(!pq.empty()){
        data current=pq.top();
        ans.push_back(current.element);
        pq.pop();
        
        int value=current.element;
        int array_position=current.ap;
        int array_index=current.ai;
        
        /*
            Condition check to determin if some other elements are present in the array from which we 
            have inserted into the answer array
        
        
        */
        if(array_index+1< arr[array_position].size()){
            
            data d1(arr[array_position][array_index+1],array_position,array_index+1);
            
            pq.push(d1);
        }
        
    }
    
    return ans;
    
    
    
    
    
    
       
    }
};