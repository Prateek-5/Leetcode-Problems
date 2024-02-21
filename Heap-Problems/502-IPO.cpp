/*
Suppose LeetCode will start its IPO soon. In order to sell a good price of its shares to Venture Capital, LeetCode would like to work on some projects to increase its capital before the IPO. Since it has limited resources, it can only finish at most k distinct projects before the IPO. Help LeetCode design the best way to maximize its total capital after finishing at most k distinct projects.

You are given n projects where the ith project has a pure profit profits[i] and a minimum capital of capital[i] is needed to start it.

Initially, you have w capital. When you finish a project, you will obtain its pure profit and the profit will be added to your total capital.

Pick a list of at most k distinct projects from given projects to maximize your final capital, and return the final maximized capital.

The answer is guaranteed to fit in a 32-bit signed integer.

 

Example 1:

Input: k = 2, w = 0, profits = [1,2,3], capital = [0,1,1]
Output: 4
Explanation: Since your initial capital is 0, you can only start the project indexed 0.
After finishing it you will obtain profit 1 and your capital becomes 1.
With capital 1, you can either start the project indexed 1 or the project indexed 2.
Since you can choose at most 2 projects, you need to finish the project indexed 2 to get the maximum capital.
Therefore, output the final maximized capital, which is 0 + 1 + 3 = 4.
Example 2:

Input: k = 3, w = 0, profits = [1,2,3], capital = [0,1,2]
Output: 6
 

Constraints:

1 <= k <= 105
0 <= w <= 109
n == profits.length
n == capital.length
1 <= n <= 105
0 <= profits[i] <= 104
0 <= capital[i] <= 109

*/




class Solution {
public:
/*
    Sudo-Code / Algorithm
    -Create a vector<pair<int,int>> it store the captial and profit
    -Sort the vector according to the foolwing parameter
        -As per the capital
        -If the capital is same then by Profit
        -We have to write a comperator function for the same
    -Once we have done that we have to make k transaction to the w(given in the question)
    -Each transaction thatwe make in W is determined by the fact that how many projects are underneath the 
        given w and out the the multiple project and their correspondin ggprofit we need to choose the max profit
    
    -Return the value of tatal max profit whichis the sum of the max Profit


*/
    /*
        The custom comperator function to sort the list according to the capital and if the capital
        is equal that according to the max profit
    */
    static bool compare(pair<int,int>& a,pair<int,int>& b){
        if(a.first==b.first){
            return a.second>b.second;
        }
        return a.first<b.first;
    }



    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        //Its a pair of vector to accomudate the value of both the capital and profit
        vector<pair<int,int>> cap_profit;

        for(int i=0;i<profits.size();i++){
            cap_profit.push_back({capital[i],profits[i]});
        }
        sort(cap_profit.begin(),cap_profit.end(),compare);

        // for(auto numbers:cap_profit){
        //     cout<<numbers.first<<" "<<numbers.second<<endl;

        // }

        int n=profits.size();
        int i=0;

        //Max heap

        priority_queue<int> pq;
        int total_profit=0;
        while(k>0){
            /*
                The following while loop is repsponcible to all all the profir which can be obtained
                using the present capital which is been store in w
            
            */
            while(i<n && w>=cap_profit[i].first){
                //cout<<i<<" "<<cap_profit[i].second<<endl;

                pq.push(cap_profit[i].second);
                i++;
            }
            /*
                We have to be very particulat about this case at there can be condtion
                where we are not able to acquire any new project based on the current capital
                at that point we should break the folliwng loop immediatly  

            */    
            if(pq.empty())  break;
            //cout<<" The max profit out of the total project"<<pq.top()<<endl;

            /*
                All the miximul profit to out current working capital that is w
                Make sure we should not initilaize any new variable to sore the profit because
                the total profit  that we will be returning is the sum of the profit that we acquired
                and the profit the we have generated
            
            */
            w+=pq.top();

            pq.pop();
            k--;

        }

        return w;










    }
};