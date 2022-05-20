/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        ListNode *first = headA, *second = headB;
        while(first != NULL && second != NULL) {
             if(first == second)
                return first;
            first = first->next;
            second = second->next;
             if(first == NULL && second == NULL)
                 return NULL;
            if(first == NULL)
                first = headB;
            if(second == NULL)
                second = headA;
            // cout<<second->val<<"     "<<first->val<<endl;
            
        }
        
        return NULL;
    }
};