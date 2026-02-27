// Question2/student.c
// ------------------------------------------------------------
// CS Lab03 - Swap Nodes in Pairs 
//
// TODO:
//   Implement swapPairs(head) to swap every two adjacent nodes.
//
// Rules:
// - Do not allocate new nodes.
// - Do not swap values; swap nodes (rewire pointers).
// - Return the new head pointer.
// ------------------------------------------------------------
#include "student.h"

struct ListNode* swapPairs(struct ListNode* head) {
    // Edge case: if the list is empty or has only one node, nothing to swap
    if (head == NULL || head->next == NULL) return head;

    struct ListNode* start = head->next;

    struct ListNode* prev = NULL;
    struct ListNode* initial = head;
    struct ListNode* pair = NULL;

    while (initial != NULL && initial->next != NULL) {
        
        pair = initial->next;

        // Step 2: The Swap
        initial->next = pair->next; 
        pair->next = initial;       // 2 points to 1

        // Step 3: The Stitch
        if (prev != NULL) {
            prev->next = pair;      // Previous pair points to the new front (2)
        }

        // Step 4: Move Forward
        prev = initial;             // 'initial' is now the tail of this pair
        initial = initial->next;    // Move to the start of the next pair (node 3)
    }

    return start;
}

 