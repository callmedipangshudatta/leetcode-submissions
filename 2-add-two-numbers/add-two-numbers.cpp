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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // 1. Build the starting line (The Dummy Node)
        ListNode dummy(0);
        ListNode* curr = &dummy; // 'curr' will do the walking and building
        
        int carry = 0; // To hold our math carry-over (like 8 + 5 = 13, carry 1)
        
        // 2. Keep looping as long as there are numbers to add, OR a leftover carry
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            
            // If l1 is empty, treat its value as 0
            int val1 = (l1 != nullptr) ? l1->val : 0;
            // If l2 is empty, treat its value as 0
            int val2 = (l2 != nullptr) ? l2->val : 0;
            
            // 3. Do the primary school math
            int total = val1 + val2 + carry;
            carry = total / 10;        // e.g., 13 / 10 = 1 (This is the new carry)
            int finalDigit = total % 10; // e.g., 13 % 10 = 3 (This goes in the node)
            
            // 4. Create a brand new box for the answer, and attach it to our list
            curr->next = new ListNode(finalDigit);
            
            // 5. Move all our workers forward for the next round
            curr = curr->next;
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }
        
        // 6. Return the real start of the answer list (ignoring the dummy 0)
        return dummy.next;
    }
};