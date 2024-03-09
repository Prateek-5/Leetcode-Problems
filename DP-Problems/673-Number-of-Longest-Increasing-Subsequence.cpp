/*
Given an integer array nums, return the number of longest increasing subsequences.

Notice that the sequence has to be strictly increasing.

 

Example 1:

Input: nums = [1,3,5,4,7]
Output: 2
Explanation: The two longest increasing subsequences are [1, 3, 4, 7] and [1, 3, 5, 7].
Example 2:

Input: nums = [2,2,2,2,2]
Output: 5
Explanation: The length of the longest increasing subsequence is 1, and there are 5 increasing subsequences of length 1, so output 5.
 

Constraints:

1 <= nums.length <= 2000
-106 <= nums[i] <= 106
*/
class Solution {
public:
    /*
        Intution / Basic ALgorithm

        We can go for the bottom-up approch for calculation in the longest incressing subsequence
        that is of time complexity O(n*n) since in the constraints
            1 <= nums.length <= 2000
            -106 <= nums[i] <= 106
        the array size is quite less

        We reqiuire a additional vector for this question 
            -We will maintain an additional vector for the for calculationg the list value as usual that is the dp vector
            -But in this case we have to maintain a count vector also that will help us determine ho many lis are possible at
                the given index
            additional details explained in the comments
    
    */


    int findNumberOfLIS(vector<int>& nums) {

        int n=nums.size();    
        vector<int> dp(n,1);
        vector<int> count(n,1);
        int maxLis=1;
        for(int i=1;i<n;i++)
        {
            for(int j=i-1;j>=0;j--)
            {   
                /*
                    The first condition specifies that we have got the first element that is smaller than ith index
                    then we can incress the length of out list for ths index by 1 and now the updated list for the particulr index is 
                    dp[i]=dp[j]+1

                    But now suppose at j we have 3 longest subsequence
                    that is 
                        1 5 7 
                        3 6 7
                        2 4 7
                    and our ith element is 10
                    So it can be addded at the end of ablove 3 subsequence that makes the lenght of lis be 3+1=4
                    but regarding the number of subsequece 10 can be added to all the 3 sub-sequece and it will make the lenght as 4

                    So the total number of subsequece of lenght 4 would be 3 itself the count if the jth variabble 



                
                */
                if(nums[j]<nums[i] && dp[i]<dp[j]+1)
                {
                    dp[i]=max(dp[i],dp[j]+1);
                    count[i]=count[j];
                }
                /*
                    The below case deals with the fact that we already have a subsequce of lenght 4 but we got another smaller
                    element which can make us achieve the same lenght of lis for that case we can do is 

                     we can perviously make 3 combinations for the 
                      that we if we consider above sudo example
                        1 5 7 10
                        3 6 7 10
                        2 4 7 10
                    now we have got another smaller index whose value is  1 2 3 ending at 3
                    we ca add 10 to the last of 3 and make a lis of length 4 
                    so we can add the follwing combination also in the  the count of i
                    thak makes count[i]+=count[j]
                
                */
                else if(nums[j]<nums[i] && dp[i]==dp[j]+1)
                {
                    count[i]+=count[j];
                }
            }
            maxLis=max(dp[i],maxLis);
        }

        int finalCount=0;
        for(int i=0;i<n;i++)
        {   
            if(dp[i]==maxLis)
            {
                finalCount+=count[i];
            }
        }
        return finalCount;





    }
};
