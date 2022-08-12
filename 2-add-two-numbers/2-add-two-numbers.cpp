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
    void assign(int val, int &carry, ListNode *l1) {
        if(val > 9)
              {
                  int k = val%10;
                  val /= 10;
                  carry = val%10;
                  l1->val = k;
              }
              else
                  l1->val = val;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
          ListNode *ans = l1;
          ListNode *prev1, *prev2;
          int carry = 0;
          while(l1 != NULL && l2 != NULL) {
              int val = l1->val+l2->val + carry;
              carry = 0;
              assign(val, carry, l1);
              
              prev1 = l1;
              prev2 = l2;
              l1 = l1->next;
              l2 = l2->next;
          }
          if(l1 == NULL && l2 != NULL) {
              prev2->next = NULL;
              prev1->next = l2;
              l1 = l2;
          }
          while(l1 != NULL) {
              int val = l1->val + carry;
              carry = 0;
              assign(val, carry, l1);
              prev1 = l1;
              l1 = l1->next;
          }
          if(carry > 0)
              prev1->next = new ListNode(carry);
          
        return ans;
    }
};