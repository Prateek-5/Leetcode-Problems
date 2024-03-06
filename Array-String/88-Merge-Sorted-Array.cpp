/*
    You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

    Merge nums1 and nums2 into a single array sorted in non-decreasing order.

    The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

    

    Example 1:

    Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
    Output: [1,2,2,3,5,6]
    Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
    The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
    Example 2:

    Input: nums1 = [1], m = 1, nums2 = [], n = 0
    Output: [1]
    Explanation: The arrays we are merging are [1] and [].
    The result of the merge is [1].
    Example 3:

    Input: nums1 = [0], m = 0, nums2 = [1], n = 1
    Output: [1]
    Explanation: The arrays we are merging are [] and [1].
    The result of the merge is [1].
    Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.
    

    Constraints:

    nums1.length == m + n
    nums2.length == n
    0 <= m, n <= 200
    1 <= m + n <= 200
    -109 <= nums1[i], nums2[j] <= 109
    

    Follow up: Can you come up with an algorithm that runs in O(m + n) time?


*/

/*
    In the following proble we have to simplly merge the array the to logic for olving the following problem is to 
    initialize a k variable equal to the combined size of the arrays -1.

    Frame the condition in a way the that the grater element is been assigned to the kth index and the the arrays 
    from which the kth index is been assigned that array index should be decremented 
    continue the following process until the ith or the jth index is been equal to zero

    Since the array performs the in-place modification of the nums1 array ith index there is no need to keep a check for 
    the ith index but for the jth index we need to place an additonla cace if some elements are left the we need to add those to the 
    array

    As show in the code below the remaining elements of the array are been added to the nums1 array 



*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1;
        int j=n-1;
        int k=m+n-1;

        while(i>=0 && j>=0){
            if(nums1[i]>=nums2[j]){
                nums1[k]=nums1[i];
                i--;
            }
            else{
                nums1[k]=nums2[j];
                j--;
            }

            k--;
        }

        while(j>=0){
            nums1[k]=nums2[j];
            k--;
            j--;
        }
    }
};
class Solution {
public:
    /*
        Intution / Basic Idea

        -Since in the question its's given that the input array are in non-decressing order
        -And we are provided up with the size of both the array and the total size
        -We start filling the aray from the back side in decressing order 
            -The larger element gets inserted and we decrement that counter
            -If any of the array gets exusted first we write a seperate logic to insert all the 
                elements fromt he other array
    
    
    */



    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int size=m+n-1;
        int i=m-1;
        int j=n-1;
        while(i>=0 && j>=0)
        {
            if(nums1[i] >= nums2[j])
            {
                nums1[size]=nums1[i];
                i--;
            }
            else{
                nums1[size]=nums2[j];
                j--;
            }
            size--;
        }
        while(i>=0)
        {
            nums1[size]=nums1[i];
            size--;
            i--;
        }
        while(j>=0)
        {
            nums1[size]=nums2[j];
            size--;
            j--;
        }

    }
};