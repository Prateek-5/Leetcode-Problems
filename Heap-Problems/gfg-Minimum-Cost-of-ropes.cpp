/*
There are given N ropes of different lengths, we need to connect these ropes into one rope. 
The cost to connect two ropes is equal to sum of their lengths.
The task is to connect the ropes with minimum cost. 
Given N size array arr[] contains the lengths of the ropes. 


Input:
n = 4
arr[] = {4, 3, 2, 6}
Output: 
29
Explanation:
We can connect the ropes in following ways.
1) First connect ropes of lengths 2 and 3.
Which makes the array {4, 5, 6}. Cost of
this operation 2+3 = 5. 
2) Now connect ropes of lengths 4 and 5.
Which makes the array {9, 6}. Cost of
this operation 4+5 = 9.
3) Finally connect the two ropes and all
ropes have connected. Cost of this 
operation 9+6 =15
Total cost for connecting all ropes is 5
+ 9 + 15 = 29. This is the optimized cost
for connecting ropes. 
Other ways of connecting ropes would always 
have same or more cost. For example, if we 
connect 4 and 6 first (we get three rope of 3,
2 and 10), then connect 10 and 3 (we get
two rope of 13 and 2). Finally we
connect 13 and 2. Total cost in this way
is 10 + 13 + 15 = 38.


*/


class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Your code here
        priority_queue<long long,vector<long long>,greater<long long>> pq;
        /*
            The basic idea to solve the following question is to add the result in the cost 
            So we always need to have the access to the min cost (either the min cost can be from the
            array element or the cost that we recently obtained) so to get a hold of the following we need
            to keep on fetchig the result from the minHead abd then puch back the result back into the heap
            
            
            Through we will always ensure that we are adding the minCost
            
            Since we are extracting (Extract min) 2 time we need to keep a conditional chekc that the 
            lenght of the array is always greated than the min cost
            
            
            )
        
        */
        
        for(int i=0;i<n;i++){
            pq.push(arr[i]);
        }
        
        
        
        long long ans=0;
        while(pq.size()>1){
            long long p1=pq.top();
            pq.pop();
            long long p2=pq.top();
            pq.pop();
            
            long long cost=p1+p2;
            ans+=cost;
            pq.push(cost);
            
            
        }
        
        return ans;
        
        
        
        
    }
};