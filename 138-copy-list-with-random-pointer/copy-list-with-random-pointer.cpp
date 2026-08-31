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
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;

        //  Step-1

        //we started our traversal pointer at the very beginning of original LL
        Node* curr = head;

        //this loop run until it hits 'nullptr'
        while(curr){
            //created new exact node
            Node* clone = new Node(curr->val);
            clone->next = curr->next;
            curr->next = clone;
            curr = clone->next;
        }

        //Step - 2 Assign random pointers to the cloned nodes
        curr = head;
        while(curr){
            if(curr->random){
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        curr = head;
        Node* dummy = new Node(0);
        Node* copyCurr = dummy;

        while(curr){
            copyCurr->next = curr->next;
            copyCurr = copyCurr->next;
            curr->next = copyCurr->next;
            curr = curr->next;
        }
        return dummy->next;
        
    }
};