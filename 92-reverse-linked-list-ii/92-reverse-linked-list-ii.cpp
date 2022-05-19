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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        ListNode *leftNode, *leftPrev, *curr = head;
        int pos = 1;
        while(pos < left){
            leftPrev = curr;
            curr = curr->next;
            pos += 1;
        }
        
        leftNode = curr;
        ListNode *prev = NULL, *temp = NULL;
        while(pos < right+1) {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
            pos += 1;
        }
         leftNode->next = curr;
         if(left == 1)
            return prev;
        leftPrev->next = prev;
       
       
        return head;
    }
};