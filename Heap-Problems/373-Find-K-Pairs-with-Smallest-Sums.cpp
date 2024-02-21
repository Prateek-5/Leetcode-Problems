/*
You are given two integer arrays nums1 and nums2 sorted in non-decreasing order and an integer k.

Define a pair (u, v) which consists of one element from the first array and one element from the second array.

Return the k pairs (u1, v1), (u2, v2), ..., (uk, vk) with the smallest sums.

 

Example 1:

Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
Output: [[1,2],[1,4],[1,6]]
Explanation: The first 3 pairs are returned from the sequence: [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
Example 2:

Input: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
Output: [[1,1],[1,1]]
Explanation: The first 2 pairs are returned from the sequence: [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
 

Constraints:

1 <= nums1.length, nums2.length <= 105
-109 <= nums1[i], nums2[i] <= 109
nums1 and nums2 both are sorted in non-decreasing order.
1 <= k <= 104
k <= nums1.length * nums2.length

*/

typedef pair<int,vector<int>> pt;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pt >pq;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                int sum=nums1[i]+nums2[j];
                /*
                    The following case ensure that we are short of the required ask of the number of pairs
                    that's why any how we have to include the pair in the array
                */ 
                if(pq.size()<k){
                    pq.push({sum,{nums1[i],nums2[j]}}) ;
                }
                /*
                    If the sum which we have optained is less than the min Sum we have in the minHeap
                    then no need to increase the size of the heap and the cost of rebalancing it so we 
                    pop out the element from the heap

                    This is more of a space optimization step
                */
                else if(sum < pq.top().first) {
                    pq.pop();
                    pq.push({sum,{nums1[i],nums2[j]}}) ;
               }
               /*
                    Given in question " You are given two integer arrays nums1 and nums2 sorted in non-decreasing order"
                    Few condition are there
                        -The sum which we have optained is not less than the minSum that we have
                        -Our priority_queue is already filled 
                    Which means that the sum that we will get will be eventually greater than the 
                    max sum which we have in our max heap

                    So we need not compute futher and end the following iteration
                    This is more of a time optimization step
               */
               else{
                    break;
               }
            }
        }

        
        vector<vector<int>> ans;

        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;




    }
};