class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        //Solved Using HashMap. As a + b = target => a = target-b
        //So if we already have element that we get after subtracting current element from targetSum. Then we say that we find the pairs.
        //TC: O(n);
        //SC: O(n);
        int size = nums.size();
        map<int,int>g;
        
        for(int itr = 0; itr < size; itr++)
        {
            int b = nums[itr];
            int a = target - b;
            if(g.count(a)) {
                return vector<int>() = {g[a], itr};
            }
            g[nums[itr]] = itr; // storing element as key and index as value.
        }
        return vector<int>();
        
        
        
        
        //We will also solve this problem using two pointers. For this first we will declare vector of pairs and store pair of element and its index in it, for all elements. And then we perform sorting, based on element value.
        //TC: O(nlogn);
        //SC: O(2n);
        /*
        
        
        //Just Idea, Not demonstrated Actual Implementation.
        int size = nums.size();
        int left = 0, right = size-1;
   
        sort(nums.begin(), nums.end());
        while(left < right) {
            int sum = (nums[left]+nums[right]);
            cout<<sum<<endl;
            if(sum == target)
                return vector<int>() = {left, right};
            else if(sum < target)
               left++;
            else
               right--;
        }
        
        return vector<int>();
        
        */
    }
};