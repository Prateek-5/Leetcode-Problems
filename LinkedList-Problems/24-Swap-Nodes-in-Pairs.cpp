/*
Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

 

Example 1:


Input: head = [1,2,3,4]
Output: [2,1,4,3]
Example 2:

Input: head = []
Output: []
Example 3:

Input: head = [1]
Output: [1]
 

Constraints:

The number of nodes in the list is in the range [0, 100].
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
    ListNode* swapPairs(ListNode* head) {
        /*
            Corner cases if a null or a singlton linked list is passed
        
        */

        if(head==nullptr || head->next==nullptr)    return head;
        ListNode* temp=head;

        /*
            Conditionts so thatwe can traverse the whole linked list
        */

        while(temp!=nullptr && temp->next!=nullptr)
        {
            /*
                Values to be swapped
            */
            int tempValue=temp->val;
            int tempNextValue=temp->next->val;
            /*
                Actual swap operation
            */
            temp->val=tempNextValue;
            temp->next->val=tempValue;
            /*
                Increment og the temp variable
            */
            temp=temp->next->next;
        }
        return head;
    }
};