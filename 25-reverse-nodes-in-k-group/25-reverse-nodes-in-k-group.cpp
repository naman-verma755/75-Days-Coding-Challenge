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
    int countNodes(ListNode *head) {
        int count = 0;
        
        while(head != NULL)
        {
            count++;
            head = head->next;
        }
        return count;
    }
    ListNode* reverse(ListNode *head, int &k, int count, int &totalNodes) {
        
        if((totalNodes-count) < k)
            return head;
        // cout<<head->val;
        
        ListNode *curr = head, *temp, *prev = NULL;
        int counter = 1;
        
        while(counter <= k) {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
            counter += 1;
        }
        head->next = reverse(curr, k, (count+k), totalNodes);
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        int totalNodes = countNodes(head);
        // cout<<head->next->val<<" ";
        // cout<<totalNodes;
        int count = 0;
        return reverse(head, k, count, totalNodes);
        return NULL;
    }
};