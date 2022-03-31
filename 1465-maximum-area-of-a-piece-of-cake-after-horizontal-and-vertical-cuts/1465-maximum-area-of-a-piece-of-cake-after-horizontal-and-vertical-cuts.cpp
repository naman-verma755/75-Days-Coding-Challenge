class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int mod = 1000000007;
         sort(horizontalCuts.begin(), horizontalCuts.end());
        int maxH = horizontalCuts[0];
        
        int curr = horizontalCuts[0];
       
        int sizeH = horizontalCuts.size();
        for(int i = 1; i < sizeH; i++) {
            maxH= max(maxH, horizontalCuts[i]-curr);
            curr = horizontalCuts[i];
        }
        maxH= max(maxH, h-curr);
        // cout<<maxH;
        
         sort(verticalCuts.begin(), verticalCuts.end());
        int maxV = verticalCuts[0];
        curr = verticalCuts[0];
       
        int sizeV = verticalCuts.size();
        for(int i = 1; i < sizeV; i++) {
            maxV = max(maxV, verticalCuts[i]-curr);
            curr = verticalCuts[i];
        }
        maxV = max(maxV, w-curr);
        long long ans = maxH;
        ans = (ans*maxV)%mod;
        return ans; 
    }
};