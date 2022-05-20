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
    int countNodes(ListNode*head){
        int c = 0;
        while(head!=NULL)
        {
            head = head->next;
            c++;
        }
        return c;
    }
    ListNode* reverse(ListNode *head, int length, int totalNodes) {
        if(head == NULL || head->next == NULL)
            return head;
        // cout<<length<<" ";
        // cout<<head->val<<" ";
        int r = length-1;
        r = (r*(r+1))/2;
        // cout<<r<<endl;
        if((totalNodes-r) < length)
        {
            length = totalNodes-r;
            if(length&1)
                return head;
        }
        if(length&1) {
            ListNode* curr = head, *prev = NULL;
            int count = 1;
            while(curr != NULL && count <= length) {
                prev = curr;
                curr = curr->next;
                count+=1;
            }
            // if()
            prev->next = reverse(curr, length+1, totalNodes);
            return head;
        }
        else {
            ListNode *curr = head, *prev = NULL;
            int count = 1;
            while(curr != NULL && count <= length) {
                ListNode *temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
                count+=1;
            }
             head->next = reverse(curr, length+1, totalNodes);
        return prev;
        }
        return NULL;
       
    }
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        int totalNodes = countNodes(head);
        return reverse(head, 1, totalNodes);
    
      
    }
};