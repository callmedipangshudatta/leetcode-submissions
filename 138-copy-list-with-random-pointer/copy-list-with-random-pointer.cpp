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
        if(!head){
            return nullptr;
        }
        
        Node* curr = head;
        while(curr){
            Node* nextNode = curr->next;
            curr->next = new Node(curr->val);
            curr->next->next = nextNode;
            curr = nextNode;
        }

        curr = head;
        while(curr){
            if(curr->random){
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        curr = head;
        Node* pseudoHead = new Node(0);
        Node* copyCurr = pseudoHead;

        while(curr){
            copyCurr->next = curr->next;
            copyCurr = copyCurr->next;
            curr->next = curr->next->next;
            curr = curr->next;
        }
        return pseudoHead->next;
    }
};