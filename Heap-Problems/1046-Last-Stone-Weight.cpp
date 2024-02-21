/*
You are given an array of integers stones where stones[i] is the weight of the ith stone.

We are playing a game with the stones. On each turn, we choose the heaviest two stones and smash them together. Suppose the heaviest two stones have weights x and y with x <= y. The result of this smash is:

If x == y, both stones are destroyed, and
If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.
At the end of the game, there is at most one stone left.

Return the weight of the last remaining stone. If there are no stones left, return 0.

 

Example 1:

Input: stones = [2,7,4,1,8,1]
Output: 1
Explanation: 
We combine 7 and 8 to get 1 so the array converts to [2,4,1,1,1] then,
we combine 2 and 4 to get 2 so the array converts to [2,1,1,1] then,
we combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
we combine 1 and 1 to get 0 so the array converts to [1] then that's the value of the last stone.
Example 2:

Input: stones = [1]
Output: 1
 

Constraints:

1 <= stones.length <= 30
1 <= stones[i] <= 1000

*/

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;

        /*
            Add all the elemensts into the array and store it into a max heap
        */


        for(int numbers:stones){
            pq.push(numbers);
        }
        /*
            Since we need to retunr the last element we need to be sure of the seze of the priority queue
            Algo
                -Fetch out 1st the maximum store it in x
                -Fetch out the 2nd maximum store it in y
                -If the x and y are not equal that means they would not cancel out each other so we need
                    to store the difference between then as a new stone
                -We will repeate the follwing process until there is only 1 or zero store left in the heap
                -Corner case if there is only 1 store left return pq.top()
                -If the last 2 stones cancel out each other then we need to to return -1
                    

        
        
        */
        while(pq.size()>1){
            int x=pq.top();
            pq.pop();
            int y=pq.top();
            pq.pop();
            cout<<x<<" "<<y<<endl;
            if(x!=y){
                cout<<(y-x)<<endl;
                pq.push(x-y);
            }
        }
        return pq.empty() ? 0 :pq.top();
    }
};