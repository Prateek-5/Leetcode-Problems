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

    /*
        dummy->1->2->3->4
        prev->curr->2->3->4

        1.Make 2 the first node
            prev->next=curr->next
        
            dummy->2<-1
                   |
                   V
                   3
                   |
                   V
                   4
        2.Make the next of 2 to be the next of 1
            curr->next=prev->next->next
            dummy->2 1->3->4->5
        3. now the link between 2 nd 1 is broken 
            so prev->next->next=curr
            dummy->2->1->3->4->5
        4.Currently prev points to dummy
            and curr points to 2
        prev=curr
        curr=curr->next
        prev points to 3
        Now curr points to 1

        repeat until curr!=nullptr or curr->next!=nullptr
    
    */


    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr || head->next==nullptr)    return head;
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;

        ListNode* prev=dummy;
        ListNode* curr=head;

        while(curr!=nullptr && curr->next!=nullptr)
        {
            /*
                Creation and destruction of link between nodes
            */
            prev->next=curr->next;
            curr->next=prev->next->next;
            prev->next->next=curr;

            /*
                Updation of link for the next iteration
            */

            prev=curr;
            curr=curr->next;
    
        }
        return dummy->next;


    }
};



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