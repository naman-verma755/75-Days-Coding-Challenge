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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        
        ListNode *slow = head, *fast = head;
        
        int count = 0;
        while(count < n) {
            fast = fast->next;
            count++;
        }
        if(fast == NULL)
        {
            fast = slow->next;
            slow->next = NULL;
            delete slow;
            return fast;
        }
        while(fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
        ListNode *node = slow->next;
        slow->next = node->next;
        node->next = NULL;
        delete node;
        return head;
    }
};