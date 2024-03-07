/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

Example 1:


Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
 

Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.

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

        -There are 3 important things we need for creating the new Linked list which denotes the sum of the numbers
            -Total Sum of both the nodes + remainder
            -Node value obtained by mod of the sum%10 (this value is user to create the new Linked list node)
            -Remainder it's the total sum by 10 (it's will be used for the caculation of totalSum of the next node as well)
        -Keep a check for the result head and tail and write corner condition for their updation
        -The return of the folliwng function ids the result head;
        -if even after the last total sum calculation if their is a remainder we need to consider that as well so
            write an explicit condition for it's node creating and attaching it to the result linkedlist
    
    
    
    
    */




    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int remainder=0;
        ListNode* num1=l1;
        ListNode* num2=l2;
        ListNode* resultHead=nullptr;
        ListNode* resultTail=nullptr;
        while(num1!=nullptr && num2!=nullptr)
        {
            int totalSum=num1->val + num2->val + remainder;
            int nodeValue=totalSum%10;
            remainder=totalSum/10;

            if(resultHead==nullptr)
            {
                ListNode* newElement=new ListNode(nodeValue);
                resultHead=newElement;
                resultTail=newElement;
            }
            else
            {
                ListNode* newElement=new ListNode(nodeValue);
                resultTail->next=newElement;
                resultTail=resultTail->next;
            }
            num1=num1->next;
            num2=num2->next;
        }

        while(num1!=nullptr)
        {
            int totalSum=num1->val + remainder;
            int nodeValue=totalSum%10;
            remainder=totalSum/10;
            if(resultHead==nullptr)
            {
                ListNode* newElement=new ListNode(nodeValue);
                resultHead=newElement;
                resultTail=newElement;
            }
            else
            {
                ListNode* newElement=new ListNode(nodeValue);
                resultTail->next=newElement;
                resultTail=resultTail->next;
            }
            num1=num1->next; 
        }
        while(num2!=nullptr)
        {
            int totalSum=num2->val + remainder;
            int nodeValue=totalSum%10;
            remainder=totalSum/10;
            if(resultHead==nullptr)
            {
                ListNode* newElement=new ListNode(nodeValue);
                resultHead=newElement;
                resultTail=newElement;
            }
            else
            {
                ListNode* newElement=new ListNode(nodeValue);
                resultTail->next=newElement;
                resultTail=resultTail->next;
            }
            num2=num2->next; 
        }
        if(remainder!=0)
        {
            if(resultHead==nullptr)
            {
                ListNode* newElement=new ListNode(remainder);
                resultHead=newElement;
                resultTail=newElement;
            }
            else
            {
                ListNode* newElement=new ListNode(remainder);
                resultTail->next=newElement;
                resultTail=resultTail->next;
            }
        }

        return resultHead;

    }
};