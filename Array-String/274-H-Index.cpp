/*
Given an array of integers citations where citations[i] is the number of citations a researcher received for their ith paper, return the researcher's h-index.

According to the definition of h-index on Wikipedia: The h-index is defined as the maximum value of h such that the given researcher has published at least h papers that have each been cited at least h times.

 

Example 1:

Input: citations = [3,0,6,1,5]
Output: 3
Explanation: [3,0,6,1,5] means the researcher has 5 papers in total and each of them had received 3, 0, 6, 1, 5 citations respectively.
Since the researcher has 3 papers with at least 3 citations each and the remaining two with no more than 3 citations each, their h-index is 3.
Example 2:

Input: citations = [1,3,1]
Output: 1
 

Constraints:

n == citations.length
1 <= n <= 5000
0 <= citations[i] <= 1000

*/

class Solution {
public:

    /*
        Intution / Basic Algorithm

        3 0 6 1 5 ->    0 1 3 5 6 (at least 3 papers with 3 citations 0 1 3 ) 
        1 3 1 ->        1 1 3 (at least 1 paper with 1 citations)

        Algorithm
            Sort the given array
            initialize the low and high for the array size
            Search for the followinf condition in the binary search
                citations[mid]==n-mid return n-mid
                citations[mid] > n-mid  high=mid-1;
                citations[mid] < n-mid  low=mid+1;
            At the end return n-low
                exampe if there are 1 citations(first one) then low will be n-1
                and n-(n-1)==> 1  
    */


    int solve(vector<int>& citations)
    {
        int low=0;
        int high=citations.size()-1;
        int n=citations.size();
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(citations[mid]==n-mid)
                return citations[mid];
            else if(citations[mid] > n-mid)
                high=mid-1;
            else{
                low=mid+1;
            }
        }

        return n-low;



    }




    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end());
        return solve(citations);
    }
};