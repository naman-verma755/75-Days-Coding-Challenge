class ll {
    public:
    int val;
    ll *prev;
    ll *next;
    
    
    ll(int _val) {
        // cout<<_val<<" ";
        val = _val;
        prev = next = NULL;
    }
};

class Dqueue {
    public:

    ll *tail;
    ll *head;
    ll *t;
    ll *h;
    
    Dqueue() {
        tail = new ll(-1);
        head = new ll(-1);
        tail->next = head;
        head->prev = tail;
            t = tail;
        h = head;
    }
    
    bool empty() {
        if(t->next == h)
            return true;
        return false;
    }
    void push_back(int _val) {
        ll *temp = tail->next;
        ll *newNode = new ll(_val);
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = temp;
        temp->prev = newNode;
    }
    void pop_back() {
        ll *temp = tail->next->next;
        ll *k = tail->next;
        tail->next = temp;
        temp->prev = tail;
        k->next = NULL;
        k->prev = NULL;
        delete(k);
    }
    int back() {
        // cout<<tail->next->val;
        return tail->next->val;
    }
    int front() {
        return head->prev->val;
    }
    
    void pop_front() {
        ll *temp = head->prev->prev;
        ll *k = head->prev;
        head->prev = temp;
        temp->next = head;
        k->next = NULL;
        k->prev = NULL;
        delete(k);
    }
    void print() {
        ll *r = tail->next;
        while(r->next != h) {
            cout<<r->val<<" ";
            r = r->next;
        }
    }
};

class Solution {
public:
    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        // deque<int>dq;
        Dqueue dq;
        // tail->prev = head;
        // head->next = tail;
        vector<int>ans;
        for(int i = 0; i < nums.size(); i++) {
            // cout<<"i="<<i<<endl;
            // dq.print();
            
            while(!dq.empty() && nums[i] >= nums[dq.back()]) {
                // cout<<dq.back()<<" ";
                dq.pop_back();
            }
            
            dq.push_back(i);
            if((i-dq.front()) >= k)
                dq.pop_front();
            
            if(i >= k-1)
                ans.push_back(nums[dq.front()]);
        }
        
        return ans;
    }
};