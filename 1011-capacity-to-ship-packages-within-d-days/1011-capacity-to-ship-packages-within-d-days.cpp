class Solution {
public:
    
    bool isPossible(int sum, vector<int>&weights, int days) {
        
        int day = 1;
        int currSum = 0;
        
        for(auto it : weights) {
            if(it > sum)
                return false;
            
            if(it+currSum > sum) {
                day++;
                currSum = it;
            }
            else
                currSum += it;
        }
        
        if(day <= days)
            return true;
        
        return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        
        int sum = 0;
        for(int weight : weights)
            sum += weight;
        
        int start = 1, end = sum;
        int ans = -1;
        while(start <= end) {
            int mid = (start+end)/2;
            if(isPossible(mid, weights, days)) {
                ans = mid;
                end = mid-1;
            }
            else
                start = mid+1;
        }
        
        
        return ans;
        
    }
};