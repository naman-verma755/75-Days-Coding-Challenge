class Solution {
public:
    int jump(vector<int>& nums) {
        
        int size = nums.size();
        if(size == 1)
            return 0;
        int path[size];
        // memset(path, INT_MAX, sizeof(p0
        for(int i = 0; i < size; i++)
            path[i] = INT_MAX;
        path[0] = 0;
        for(int i = 0; i < size; i++) {
            
            // path[i] = 1;
            for(int j = nums[i]+i; j > i ; j--) {
                // cout<<"o="<<i<<" "<<path[i]<<endl;
                if(j >= size-1)
                    return path[i]+1;
                
                path[j] = min(path[j], path[i]+ 1);
                
            }
            // for(int k = 0; k < size; k++)
            //    cout<<path[k]<<" ";
            // cout<<endl;
           
        }
        return path[size-1];
        
    }
};