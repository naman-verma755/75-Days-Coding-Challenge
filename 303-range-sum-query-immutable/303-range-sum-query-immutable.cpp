class NumArray {
public:
    int prefix[10004];
    NumArray(vector<int>& nums) {
        
        prefix[0] = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            prefix[i] = nums[i]+prefix[i-1];
        }
    }
    
    int sumRange(int left, int right) {
        if(left == 0)
            return prefix[right];
        return prefix[right]-prefix[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */