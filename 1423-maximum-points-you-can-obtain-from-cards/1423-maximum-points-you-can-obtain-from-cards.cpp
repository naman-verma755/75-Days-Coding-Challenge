class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int size = cardPoints.size();
        int prefixSum[size];
        prefixSum[0] = cardPoints[0];
        for(int i = 1; i < size; i++) 
            prefixSum[i] = prefixSum[i-1] + cardPoints[i];
        if(k >= size)
            return prefixSum[size-1];
        int maxi = INT_MIN;
        for(int i = k-1; i >= 0; i--) {
            int sum = 0;
            sum += prefixSum[i];
            int left = k-i-1;
            // cout<<left<<" ";
            if(left > 0) {
                sum += prefixSum[size-1]-prefixSum[size-1-left];
            }
            maxi = max(maxi, sum);
        }
        maxi = max(maxi, prefixSum[size-1]-prefixSum[size-1-k]);
        return maxi;
    }
};