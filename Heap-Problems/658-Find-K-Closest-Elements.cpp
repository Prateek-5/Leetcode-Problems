/*
Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.

An integer a is closer to x than an integer b if:

|a - x| < |b - x|, or
|a - x| == |b - x| and a < b
 

Example 1:

Input: arr = [1,2,3,4,5], k = 4, x = 3
Output: [1,2,3,4]
Example 2:

Input: arr = [1,2,3,4,5], k = 4, x = -1
Output: [1,2,3,4]
 

Constraints:

1 <= k <= arr.length
1 <= arr.length <= 104
arr is sorted in ascending order.
-104 <= arr[i], x <= 104

*/

typedef pair<int,int> pi;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pi> pq;
        /*
            Basically the follwing question is similar to the Top K-frequent element 

            what we did here is that we 
                -Initialized a maxHeap
                -store the {distance,integer}
                -if(pq.size()>k)
                    -The following condition make sure that if the diatance is greater than K is gets eliminated
                -As we have a pair stored we have a association between distance and array element
                -extrach the elements from the maxHead and store the i.second(the array element) in a vector
                -return the vector as result
        
        */
        for(int numbers:arr){
            int dist=abs(x-numbers);
            pq.push({dist,numbers});
            if(pq.size()>k){
                pq.pop();
            }
        }

        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;




    }
};