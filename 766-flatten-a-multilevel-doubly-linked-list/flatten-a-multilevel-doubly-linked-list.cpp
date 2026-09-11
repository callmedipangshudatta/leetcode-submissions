class Solution {
public:

    Node* flatten(Node* head) {
        if (head == nullptr)
            return head;

        flattenHelper(head);

        return head;
    }

    Node* flattenHelper(Node* head) {

        Node* curr = head;
        Node* tail = head;

        while (curr != nullptr) {

            Node* next = curr->next;

            if (curr->child != nullptr) {

                Node* child = curr->child;

                Node* childTail = flattenHelper(child);

                // Connect curr -> child
                curr->next = child;
                child->prev = curr;

                // Connect childTail -> next
                if (next != nullptr) {
                    childTail->next = next;
                    next->prev = childTail;
                }

                // Remove child pointer
                curr->child = nullptr;

                // The tail might now be childTail
                tail = childTail;

            } else {
                tail = curr;
            }

            curr = next;
        }

        return tail;
    }
};