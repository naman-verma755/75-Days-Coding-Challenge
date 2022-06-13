class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        vector<int>ans;   // for storing answer;
        int size = nums.size();
        
        deque<int>dq;
        
        for(int i = 0; i < size; i++) {
            
            
            while(!dq.empty() && nums[i] >= nums[dq.back()]) {
                dq.pop_back();
            }
            
            dq.push_back(i);
            
            if(dq.front() <= (i-k))
                dq.pop_front();
            
            if(i >= k-1)
                ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};