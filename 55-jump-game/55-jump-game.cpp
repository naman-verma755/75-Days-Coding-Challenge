class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int size = nums.size();
        if(size == 1)
            return true;
        int path[size];
        memset(path, 0, sizeof(path));
        path[0] = 1;
        for(int i = 0; i < size-1; i++) {
            
            if(path[i] > 0 ) {
                for(int j = i+1; j <= nums[i]+i && j < size; j++) {
                    if(j == size-1)
                        return true;
                    path[j] += 1;
                }
            }
            else
                return false;
        }
        return false;
        
    }
};