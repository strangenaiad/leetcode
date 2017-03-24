/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode*first = head;
    while( first && first->val==val )
        first = first->next;
    
    if( first )
    {
        struct ListNode*prev = first;
        struct ListNode*node = prev->next;
        while( node )
        {
            struct ListNode*next = node->next;
            if( node->val==val )
            {
                prev->next = next;
            }
            else
            {
                prev->next = node;
                prev = node;
            }
            
            node = next;
        }
    }

    return first;
}