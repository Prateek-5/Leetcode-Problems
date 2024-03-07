/*
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

 

Example 1:


Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: list1 = [], list2 = []
Output: []
Example 3:

Input: list1 = [], list2 = [0]
Output: [0]
 

Constraints:

The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.

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
        Intution / Basic Algoritm
        -Same approch that we apply while merging array we will consider the smaller node and point the 
            result pointer to that particular node and increment the list
        -Keep result head and tail for keeping the track of the resulttant linked list
        -Also keep in mind that we need to account for the situtation if one of the linked likst got exusted
            but still elements are present in the other linked list
        -Return the resultant head as the part of the answer
    
    
    */



    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* resultHead=nullptr;
        ListNode* resultTail=nullptr;

        while(list1!=nullptr && list2!=nullptr)
        {
            if(list1->val <= list2->val )
            {
                if(resultHead==nullptr)
                {
                    resultHead=list1;
                    resultTail=list1;
                    list1=list1->next;
                }
                else
                {
                    resultTail->next=list1;
                    resultTail=resultTail->next;
                    list1=list1->next;
                }
            }
            else
            {
                if(resultHead==nullptr)
                {
                    resultHead=list2;
                    resultTail=list2;
                    list2=list2->next;
                }
                else
                {
                    resultTail->next=list2;
                    resultTail=resultTail->next;
                    list2=list2->next;
                }
            }
        }
        while(list1!=nullptr)
        {
             if(resultHead==nullptr)
                {
                    resultHead=list1;
                    resultTail=list1;
                    list1=list1->next;
                }
                else
                {
                    resultTail->next=list1;
                    resultTail=resultTail->next;
                    list1=list1->next;
                }   
        }
        while(list2!=nullptr)
        {
            if(resultHead==nullptr)
            {
                resultHead=list2;
                resultTail=list2;
                list2=list2->next;
            }
            else
            {
                resultTail->next=list2;
                resultTail=resultTail->next;
                list2=list2->next;
            }
        }
        return resultHead;





    }
};
