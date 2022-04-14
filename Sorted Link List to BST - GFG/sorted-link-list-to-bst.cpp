// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct LNode
{
    int data;
    struct LNode* next;
    
    LNode(int x){
        data = x;
        next = NULL;
    }
};

struct TNode  
{  
    
    int data;  
    struct TNode* left;  
    struct TNode* right; 
    TNode(int x)
    {
        data=x;
        left=right=NULL;
    }
}; 

void preOrder(TNode* node)  
{  
    if (node == NULL)  
        return;  
    cout<<node->data<<" ";  
    preOrder(node->left);  
    preOrder(node->right);  
} 


 // } Driver Code Ends
//User function Template for C++


//User function Template for C++

/* 
//Linked List
struct LNode
{
    int data;
    struct LNode* next;
    
    LNode(int x){
        data = x;
        next = NULL;
    }
};

//Tree
struct TNode  
{  
    
    int data;  
    struct TNode* left;  
    struct TNode* right; 
    TNode(int x)
    {
        data=x;
        left=right=NULL;
    }
}; */
class Solution{
  public:
   TNode* build(LNode *head) {
       if(head == NULL)
       return NULL;
       LNode *slow = head;
       if(head->next == NULL)
       return new TNode(slow->data);
       LNode *fast = head->next, *prev = NULL;
       while(fast->next != NULL && fast->next->next != NULL) {
           slow = slow->next;
           fast = fast->next->next;
       }
       if(slow->next != NULL)
       {
           prev = slow;
           slow = slow->next;
       }
       if(prev != NULL)
       prev->next = NULL;
       LNode *nextNode = slow->next;
       slow->next = NULL;
       TNode *node = new TNode(slow->data);
       
       node->left = build(head);
       node->right = build(nextNode);
       
       return node;
   }
    TNode* sortedListToBST(LNode *head) {
        //code here
        return build(head);
        
    }
};

// { Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;

        int data;
        cin>>data;
        LNode *head = new LNode(data);
        LNode *tail = head;
        for (int i = 0; i < n-1; ++i)
        {
            cin>>data;
            tail->next = new LNode(data);
            tail = tail->next;
        }
        Solution ob;
        TNode* Thead = ob.sortedListToBST(head);
        preOrder(Thead);
        cout<<"\n";
        
    }
    return 0;
}
  // } Driver Code Ends