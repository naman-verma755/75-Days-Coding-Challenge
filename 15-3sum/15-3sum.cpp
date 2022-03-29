class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        int size = nums.size();
        if(size < 3)
            return ans;
//         set<vector<int>>st;
        
//         map<int,int>mp;
//         mp[nums[0]] ++;
//         for(int i = 1; i < size-1; i++) {
//             int a = nums[i];
//             for(int j = i+1; j < size; j++) {
//                 int b = nums[j];
//                 if(mp.count(-1*(a+b))) {
//                     vector<int>temp ={(-1*(a+b)), a, b};
//                     sort(temp.begin(), temp.end());
//                     st.insert(temp);
//                 }
                
//             }
//             mp[a] ++;
//         }
//         for(auto it = st.begin(); it != st.end(); it++) {
//             ans.push_back(*it);
//         }
        sort(nums.begin(), nums.end());
         for(int i = 0 ; i < size - 2; i++) {
             if(i > 0 && nums[i] == nums[i-1])
                 continue;
             int left = i+1;
             int right = size-1;
             while(left < right) {
                
                 int a = nums[left];
                 int b = nums[right];
                  // cout<<nums[i]<<" "<<a<<" "<<b<<endl;
                 if(nums[i] == (-1*(a + b))) {
                     // cout<<i<<endl;
                     ans.push_back(vector<int>() = {nums[i], a, b});
                     while(a == nums[left] && left < right) {
                         left++;
                     }
                     while(b == nums[right] && left < right) {
                         right--;
                     }
                 }
                 else if(nums[i] > (-1*(a+b))){
                     while(nums[right] == b && right > left)
                     {
                         right--;
                     }
                 }
                 else if(nums[i] < (-1*(a+b))) {
                     while(nums[left] == a && right> left) {
                         left ++;
                     }
                 }
                 
             }
         }
        return ans;
        
        
        
        
        
        
        
        
        
    }
};