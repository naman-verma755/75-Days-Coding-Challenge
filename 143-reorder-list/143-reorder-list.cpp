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
    ListNode* reverse(ListNode *head) {
        ListNode *prev = NULL, *curr = head, *temp;
        
        while(curr != NULL) {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    ListNode* findMid(ListNode *head) {
        ListNode *slow = head, *fast = head->next;
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
       
        return slow;
    }
    void reorderList(ListNode* head) {
        ListNode *h1 = head;
        ListNode *mid = findMid(h1);
         ListNode *nodes = mid->next;
        mid->next = NULL;
        ListNode *curr = head, *end;
        end = reverse(nodes);
        ListNode *temp1, *temp2;
        while(curr != NULL && end != NULL) {
            temp1 = curr->next;
            temp2 = end->next;
            curr->next = end;
            end->next = temp1;
            curr = temp1;
            end = temp2;
        }
        
        
        // return head;
    }
};