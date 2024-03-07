/*
A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.

Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.

Return the head of the copied linked list.

The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
Your code will only be given the head of the original linked list.

 

Example 1:


Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
Example 2:


Input: head = [[1,1],[2,1]]
Output: [[1,1],[2,1]]
Example 3:



Input: head = [[3,null],[3,0],[3,null]]
Output: [[3,null],[3,0],[3,null]]
 

Constraints:

0 <= n <= 1000
-104 <= Node.val <= 104
Node.random is null or is pointing to some node in the linked list.

*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    /*
        Intution / Basic Algorithm
        From the given linked list we need to create a copy of the same node just after the original nodels
            like if the original linked list is
                7->13->11->10->1->null
            we have to create something like this
                7->7->13->13->11->11->10->10->1->1->null
            Now using the advantage of the fact that the new linked list is just after the original liked list 
                we will update the random pointer of the new linked list as the logic written below
            Once we are done with the same we will segerateboth the liked list
            Note one corner case
                when we are seperating the original and new as the condition is for if(temp->next==nullptr)
                then only the loop breaks so we need to 
                explicitly de-link the last node of the original linked list and make it to null
                else it will remain linked to the last node of the newLinked list

    


    */



    Node* copyRandomList(Node* head) {

        if(head==nullptr)   return head;
        Node* temp=head;

        while(temp!=nullptr)
        {
            Node* newNode=new Node(temp->val);

            newNode->next=temp->next;
            temp->next=newNode;
            temp=temp->next->next;
    
        }
        temp=head;
        while(temp!=nullptr)
        {
            if(temp->random!=nullptr)
            {
                temp->next->random=temp->random->next;
                
            }
            temp=temp->next->next;
            
        }
        temp=head;
        Node* temp2=head->next;
        Node* result=temp2;
        while(temp!=nullptr && temp2!=nullptr && temp->next!=nullptr && temp2->next!=nullptr)
        {
            temp->next=temp->next->next;
            temp2->next=temp2->next->next;
            temp=temp->next;
            temp2=temp2->next;
        }
        temp->next=nullptr;
        // temp=result;
        // while(temp!=nullptr)
        // {
        //     cout<<temp->val<<" ";
        //     temp=temp->next;
        // }

        return result;



    }
};