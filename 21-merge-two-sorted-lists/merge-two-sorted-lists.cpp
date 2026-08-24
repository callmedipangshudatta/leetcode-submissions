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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        //we are making an fake anchor dummy with value 0 
        ListNode dummy(0);

        //curr is the pointer , which now anchors list 1 and list 2 elements together
        //in sorted manner
        ListNode* curr = &dummy;

        //so we are checking if both LL have no null values
        while(list1 != nullptr && list2 != nullptr){

            //so we are sorting elements
            if(list1->val <= list2->val){
                curr->next = list1;
                list1 = list1->next;
            }
            else{
                curr->next = list2;
                list2 = list2->next;
            }
            //pushing the fake anchor onto with the real element postion
            curr = curr->next;
        }
        //to check if one of the LL is out of touch -> so that we can directly insert
        //the other one
        if(list1 != nullptr){
            curr->next = list1;
        }else{
            curr->next = list2;
        }

        //dummy.next means the fake anchor now gets removed and what remains is the pure addressed element of each node in sorted manner
        return dummy.next;
    }
};



// Core Concept :-

// You set up a brand new, empty track. You park a fake "0" car at the very beginning of that track. Then, you just attach the real cars behind it, one by one.

// 1. "We set it all up onto a new track, and consider the first index as 0"
// C++
// ListNode dummy(0); 
// This is you putting the fake 0 car on the new track. It is the anchor. It is the starting line.

// 2. We need a worker to walk down the track
// C++
// ListNode* curr = &dummy;
// If dummy is the fake 0 car sitting on the track, curr is the worker doing the attaching.

// &dummy means "Go find the fake 0 car."

// curr = &dummy means the worker starts their job standing right behind the fake 0 car.

// 3. We attach cars to the new track
// C++
// curr->next = list1;
// The worker (curr) reaches out and attaches the next car (list1) to the back of whatever they are currently standing at.
// The very first time this happens, they are attaching list1 directly to the back of the fake 0 car!

// 4. We deliver the final train (without the 0)
// C++
// return dummy.next;
// When all the cars are hooked up, the new track looks like this:
// [0] -> [1] -> [1] -> [2] -> [3] -> [4]

// The problem only wants the sorted numbers, not our fake 0 setup car.
// Because dummy is the [0], dummy.next points directly to the [1].
// By returning dummy.next, we hand the grader the perfect list, leaving the fake 0 car behind.