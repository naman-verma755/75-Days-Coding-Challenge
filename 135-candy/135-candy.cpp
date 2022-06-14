class Solution {
public:
    int candy(vector<int>& ratings) {
        
        int size = ratings.size();
        int leftMax[size];
        int rightMax[size];
        
        leftMax[0] = 1;
        for(int i = 1; i < size; i++) 
            if(ratings[i] > ratings[i-1])
                leftMax[i] = leftMax[i-1]+1;
            else leftMax[i] = 1;
        
        rightMax[size-1] = 1;
        for(int i = size-2; i >= 0; i--) 
            if(ratings[i] > ratings[i+1])
                rightMax[i] = rightMax[i+1]+1;
            else
                rightMax[i] = 1;
        
        int totalCandies = 0;
        
        for(int i = 0; i < size; i++)
            totalCandies += max(leftMax[i], rightMax[i]);
        
        return totalCandies;
    }
};