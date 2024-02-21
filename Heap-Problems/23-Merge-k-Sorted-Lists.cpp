/*
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

 

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
Example 2:

Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
Output: []
 

Constraints:

k == lists.length
0 <= k <= 104
0 <= lists[i].length <= 500
-104 <= lists[i][j] <= 104
lists[i] is sorted in ascending order.
The sum of lists[i].length will not exceed 104.

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
        The following problem is also solve using the same concept thatwe used in the Merge k Sorted array
        Basically whta we do here is tune the data datatype a bit according to the LinkedList

        In the custom datatype we sore to value element which is the value present in the linked list and
        in order to iterete through the whole linked list we store the next pointer

    
    */
    class data {
    public:
        int value;
        ListNode* current;
        
        // Fixed the parameter name to avoid confusion
        data(int val, ListNode* current_list) : value(val), current(current_list) {}
    };
    /*
        The following is a custom comperator struch which overrights the operator function with the locg to
        perform the sorting based on the d.value property that's the custom datatype
    
    
    */
    struct myComp {
        bool operator()(const data& d1, const data& d2) {
            return d1.value > d2.value;
        }
    };

    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k=lists.size();
        priority_queue<data,vector<data>,myComp> pq;
        ListNode* head=nullptr;
        ListNode* tail=nullptr;
        /*
            We have initialized the head and the tail asthey are the required for the answer 
            The priority queue is been initialized using the custom datatype and the custom comperator function

            Iterate through all the listNode present in the vector<ListNode*> that is all the first elements of the 

        
        */
        for(int i=0;i<k;i++){
            
            if(lists[i]!=nullptr)
            {
                int data1=lists[i]->val;
                ListNode* current_list=lists[i];
                data d(data1,current_list);
                pq.push(d);
            }

          
        }
        
        /*
            For the Priority Queue(minHeap) extract the min and add it to the answer throught the had and tail reference
            and itereate futher throught the list from where we have pop out the node in the minHeap
        
        */

        while(!pq.empty())

        {
            data current=pq.top();
            pq.pop();

            if(head==nullptr){
                head=current.current;
                tail=head;
            }
            else{
                tail->next=current.current;
                tail=tail->next;
            }

            if(current.current->next!=nullptr){
                data d1(current.current->next->val,current.current->next);
                pq.push(d1);
            }
        }

        return head;

    }
};