/*
You are given the head of a linked list, and an integer k.

Return the head of the linked list after swapping the values of the kth node from the beginning and the kth node from the end (the list is 1-indexed).

 

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [1,4,3,2,5]
Example 2:

Input: head = [7,9,6,6,7,8,3,0,9,5], k = 5
Output: [7,9,6,6,8,7,3,0,9,5]
 

Constraints:

The number of nodes in the list is n.
1 <= k <= n <= 105
0 <= Node.val <= 100
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    /*
        Intution / Basic Algorithm

        The following proble involves the concept of of finding the 
            first nth node
            last nth node
        For the first nth node since the K is given as 1-indexed position we need to tarverse k-1 times
        for the last nth node once we have reached the first nth node we initialized a new pointer starting from dummy node
            and iterate until nth nodes becomes zero since we started with the initial difference of k
            if the fast pointer gets exusted or reached the end of the linked list it means the slow pointer is k steps behind 
            which means the last nth node
        Once we have the hold of both the nodes we swap the value of the same
    
    
    */

    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;

        int temp=k-1;
        ListNode* fast=head;
        while(temp--)
        {
            fast=fast->next;
        }
        ListNode* firstNode=fast;
        ListNode* slow=dummy;
        while(fast!=nullptr)
        {
            slow=slow->next;
            fast=fast->next;
        }

        swap(firstNode->val,slow->val);

        return head;




    }
};