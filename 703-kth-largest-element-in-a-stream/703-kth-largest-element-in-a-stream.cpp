class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>>pq;
    int r;
    KthLargest(int k, vector<int>& nums) {
        r = k;
        for(int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);
            if(pq.size() > k)
                pq.pop();
        }
    }
    
    int add(int val) {
        
        pq.push(val);
        // priority_queue<int>t = pq;
        // while(!t.empty()) {
        //     cout<<t.top()<<" ";
        //     t.pop();
        // }
        // cout<<endl;
        // cout<<r<<" ";
        if(pq.size() > r)
            pq.pop();
        return pq.top();
        
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */