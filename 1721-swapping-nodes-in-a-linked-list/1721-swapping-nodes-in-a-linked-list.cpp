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
    ListNode* swapNodes(ListNode* head, int k) {
        if(head == NULL || head->next == NULL)
            return head;

        int size = 2;
        int currSize = 1;
        
        ListNode *slow = head, *fast = head->next;
        while(fast->next != NULL && fast->next->next != NULL) {
         
            fast = fast->next->next;
          
            slow = slow->next; 
            
            size += 2;
            
        }
        if(fast->next != NULL &&  fast->next->next == NULL)
        {
            size += 1;
        }
        int c= 1;
        ListNode *node1 = head, *node2 = head;
        while(c < k)
        {
            node1 = node1->next;
            c++;
        }
        c = 1;
        while(c <= size-k) {
           node2 = node2->next;
            c++;
        }
        // cout<<node1->val<<" "<<node2->val<<endl;
        
        swap(node1->val, node2->val);
        
        
        return head;
    }
};