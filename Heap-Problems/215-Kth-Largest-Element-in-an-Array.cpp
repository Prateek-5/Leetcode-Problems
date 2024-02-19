class Solution {
 public:
  int findKthLargest(vector<int>& nums, int k) {
    /*
        the following systax is been used if we want to compute
        the minHeap as the default is the maxHead
    */
    priority_queue<int, vector<int>, greater<>> minHeap;

    /*
        Some basic intution behind the following problem
            since we want to featch out the kth largest element from the array
            we have defined a priority queue of minHead of the size K

            So any any point of time the minHeap will store the smallest to largest until K

            and we will iterate throught the whole array so that we account for all the arrays 
            and then return the 
    
    */

    /*
        nums=[3,2,1,5,6,4]
        k=2;
    
    */

    for (const int num : nums) {
      minHeap.push(num);
      if (minHeap.size() > k)
      {
        cout<<minHeap.top()<<" ";
        //1 2 3 4
        //basically the folowing numbers got removed for the minHead(Extract min) 
        minHeap.pop();
      }


        
    }
    //out motive was to bring the Kth largest at the min position of the minHeap
    return minHeap.top();
  }
};
