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
        
        ListNode *head = NULL, *prev = NULL;
        int carry = 0;
        
        while(l1 != NULL && l2 != NULL) {
            carry = l1->val + l2->val + carry;
            // cout<<carry<<" ";
            int num = carry%10;
            carry /= 10;
            ListNode *newNode = new ListNode(num);
            if(head == NULL) 
                head = newNode;
            else 
                prev->next = newNode;
               
            
            prev = newNode;
            
            l1 = l1->next;
            l2 = l2->next;
        }
         while(l1 != NULL) {
            carry = l1->val  + carry;
            int num = carry%10;
            carry /= 10;             
            ListNode *newNode = new ListNode(num);
            prev->next = newNode;
            prev = newNode;
            
            l1 = l1->next;
            
        }
         while(l2 != NULL) {
            carry = l2->val  + carry;
            int num = carry%10;
             carry /= 10;
            ListNode *newNode = new ListNode(num);
            prev->next = newNode;
            prev = newNode;
            
            l2 = l2->next;
            
        }
        if(carry != 0)
        {
            ListNode *newNode = new ListNode(carry);
            prev->next = newNode;
        }
        return head;
        
    }
};