/*
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

 

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
k is in the range [1, the number of unique elements in the array].
It is guaranteed that the answer is unique.
 

Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.

*/

typedef pair<int,int> pi;

//that's how we define macros in c++
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       map<int,int> mp;
       for(int numbers:nums){
           mp[numbers]++;
        }
        /*
            In the hash map we store the frequency of the elements present in the array

            but the challage is the  we need to return the the element absed on the frequency
            and in HashMap we do not have any mechanism to return the element based on the frequency 
        
        */
        priority_queue<pi,vector<pi>,greater<pi>> pq;

        /*
            Basically we have used the concept of priority queue we will calculate will keep a track
            of the Kth largest MinHeap which will be based on the frequency of the hashmap

            Once we have calculated that we will return the have the hold of the Kth smallest most frequenct along with the 
            element 
        
        */


        for(auto i:mp){
            pq.push({i.second,i.first});
            if(pq.size()>k){
                pq.pop();
            }
        }
        /*
            Once we have the array we will store the ans in the vector
        */
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }


        return ans;





    }
};