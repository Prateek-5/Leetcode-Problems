/*
Design a class to find the kth largest element in a stream. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Implement KthLargest class:

KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of integers nums.
int add(int val) Appends the integer val to the stream and returns the element representing the kth largest element in the stream.
 

Example 1:

Input
["KthLargest", "add", "add", "add", "add", "add"]
[[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]
Output
[null, 4, 5, 5, 8, 8]

Explanation
KthLargest kthLargest = new KthLargest(3, [4, 5, 8, 2]);
kthLargest.add(3);   // return 4
kthLargest.add(5);   // return 5
kthLargest.add(10);  // return 5
kthLargest.add(9);   // return 8
kthLargest.add(4);   // return 8
 

Constraints:

1 <= k <= 104
0 <= nums.length <= 104
-104 <= nums[i] <= 104
-104 <= val <= 104
At most 104 calls will be made to add.
It is guaranteed that there will be at least k elements in the array when you search for the kth element.

*/

class KthLargest {
public:
/*
    Basic implementation using the priority queue
*/
    priority_queue<int,vector<int>,greater<>> pq;
    //the follwing is the syntax representation of a min heap
    int K;
    //the following variables are been declare so that they can be accessed accross different functions
    KthLargest(int k, vector<int>& nums) {
        
        /*
            In the constructor function we will implement the same function to compute the
            Kth largest element that means if we fix the size of the heap to be K and then start poping
            out elements when the size of the heap becomes greater than K .
            At any given point of time the pq.top() will always return the Kth largest element

            for better understanding do a tree based dry run of the following problem 
        
        */
        K=k;
        for(int numbers:nums){
            pq.push(numbers);
            if(pq.size()>K){
                pq.pop();
            }
        }

    }
    /*
        In the add function once we have added the element we have to make sure that the pq priority queue always 
        is less that the size k if it is less that that no problem but if the sie is greater that K .Then we need to pop
        out the min Element(extractMin) and then return the pq.top()
        
    
    */
    int add(int val) {
        pq.push(val);
        if(pq.size()>K){
            pq.pop();
        }

        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */