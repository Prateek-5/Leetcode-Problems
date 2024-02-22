/*
The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.

For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
Implement the MedianFinder class:

MedianFinder() initializes the MedianFinder object.
void addNum(int num) adds the integer num from the data stream to the data structure.
double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.
 

Example 1:

Input
["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
[[], [1], [2], [], [3], []]
Output
[null, null, null, 1.5, null, 2.0]

Explanation
MedianFinder medianFinder = new MedianFinder();
medianFinder.addNum(1);    // arr = [1]
medianFinder.addNum(2);    // arr = [1, 2]
medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
medianFinder.addNum(3);    // arr[1, 2, 3]
medianFinder.findMedian(); // return 2.0
 

Constraints:

-105 <= num <= 105
There will be at least one element in the data structure before calling findMedian.
At most 5 * 104 calls will be made to addNum and findMedian.
 

Follow up:

If all integer numbers from the stream are in the range [0, 100], how would you optimize your solution?
If 99% of all integer numbers from the stream are in the range [0, 100], how would you optimize your solution?

*/

class MedianFinder {
public:
    /*
        Algo/Sudo code
            Median (n/2)th element of the sorted array of odd length
            Median {(n/2)th element + (n-1)/2th element } / 2 the avg of the two middle element
        Naive solution
            store the incomming elemenst in the vector 
                Once the "findMedian" is been called
                    -Sort the vector
                    -retutn the median beased on the lenght as discussed above
        Below is the implementation of the brute force solution
            
    
    */

    vector<int> ans;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        ans.push_back(num);
    }
    
    double findMedian() {
        int n=ans.size();
        sort(ans.begin(),ans.end());

        if( n % 2 == 0){
            return (ans[n/2]+ans[(n/2)-1])/2.0;
        }
        else{
            return ans[n/2];
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */


class MedianFinder {
public:
    /*
        Optimal Approch
            Create 2 priority queue
                Max Heap -left_max_heap 
                Min Heap -right_min_heap
            Always make sure that the element gets inserted into the left_max_heap
                Condition to insert in the left_max_heap
                    -left_max_heap is empty
                    -the element(num[i]) is less than left_max_heap.top()
                Else conditin we insert in the right_min_Heap
            Condition for rebalancing the heap size
                -If the difference between the size of the left_max_heap and right_min_heap is greater than 1
                    -There are more elemnt in left_max_heap(like 2,3,4 etc)
                    -Insert the top() element from the left_min_heap and insert in right_min_heap
                    -pop() the element from the left_max_heap
                If the size of left_max_heap is less than the right_min_heap (Totally not acceptable)
                    -Insert the top element from the right_min_heap and inser it into right_max_heap
                    -pop the top element form thr right_max_heap
                How to return the median
                    -If the sizeof (right_min_heap + left_max_heap) is 
                        -even return left_max_heap.top()+ right_min_heap.top() / 2
                        -odd return left_max_heap.top()
    */

    priority_queue<int> left_max_heap;
    priority_queue<int,vector<int>,greater<int>> right_min_heap;


    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left_max_heap.empty() || num < left_max_heap.top()){
            left_max_heap.push(num);
        }
        else{
            right_min_heap.push(num);
        }

        //Balancing the size of the heap
        if(left_max_heap.size()> right_min_heap.size()+1){
            right_min_heap.push(left_max_heap.top());
            left_max_heap.pop();
        }
        else if(left_max_heap.size() < right_min_heap.size()){
            left_max_heap.push(right_min_heap.top());
            right_min_heap.pop();

        }



    }
    
    double findMedian() {
        int n=left_max_heap.size() + right_min_heap.size();
        if(n%2==0){
            return (left_max_heap.top()+right_min_heap.top())/2.0;
            
        }
        else{
           
            return left_max_heap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */