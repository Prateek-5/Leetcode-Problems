/*
Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

 

Example 1:


Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]
Example 2:

Input: head = [5], left = 1, right = 1
Output: [5]
 

Constraints:

The number of nodes in the list is n.
1 <= n <= 500
-500 <= Node.val <= 500
1 <= left <= right <= n
 

Follow up: Could you do it in one pass?
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

        Basically it is the linked list everse algorith only with a minor modification 
        Here we have to get hold of 2 variables for a addition an step
            1->2->3->4->5   Expected result 1->4->3->2->5

            left=2 and right=4
            Sincein the question it is mentioned that these values are position it menas they are 1-indexed
        We need to make a initial traversal of left-1 time keeping a prevLeft and curr pointer
        Note we can use a dummy node to point the node before the head this way we will always have a hold of the head pointer

        once we have made the left-1 traversal currently we are at a position 
            prevleft points to 1
            curr point to 2
            subtreeStart=curr
        We take up a additionl pointer to store the value of curr which is 2 at this point as we might required this pointer
            to attach the subtree back to the original tree
        Now perform the noraml linked list reversal algo for right-left time 
            using the prev=nullptr and curr pointer
        once we will get hold of the prev pointer the last node of the subtree 
            and point the leftprev to prev
            and initially the subtreeStart->next=curr (the fist node of the subtree becomes the 
                last and gets linked back to the original linked list)
        Once we are done with the same we return dummy->next which always points to the head;
    
    */


    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==nullptr || head->next==nullptr)    return head;

        ListNode* dummy=new ListNode(-1);
        dummy->next=head;

        ListNode* curr=head;
        ListNode* leftprev=dummy;
        /*
            Initial traversals
        */
        for(int i=0;i<left-1;i++)
        {
            leftprev=leftprev->next;
            curr=curr->next;
           
        }
        /*
            Get hold of the currently first node of the subtree later the last node
        */
        ListNode* subListStart=curr;

        ListNode* prev=nullptr;
        for(int i=0;i<right-left+1;i++)
        {
            ListNode* currNext=curr->next;
            curr->next=prev;
            prev=curr;
            curr=currNext;
        }
        
        /*
            subtreeStart techically the last node of the sublist gets mapped to the original linkedlist
            leftprev gets linked to the technically the first node of the current sublist

        */

        subListStart->next=curr;
        leftprev->next=prev;

        return dummy->next;


    }
};