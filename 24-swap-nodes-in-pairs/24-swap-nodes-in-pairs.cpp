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
    ListNode* swap(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        
        ListNode *curr = head, *prev = NULL, *temp;
        int count = 1;
        while(count <= 2) {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
            count+=1;
        }
        
        head->next = swap(curr);
        return prev;
    }
    ListNode* swapPairs(ListNode* head) {
        
        return swap(head);
        
    }
};