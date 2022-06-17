class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        
        
        // 100 200 300 400  
        int size = tokens.size();
        sort(tokens.begin(), tokens.end());
        int left = 0, right = size-1;
        int maxi = 0;
        int score = 0;
        while(left <= right) {
            
            if(power < tokens[left])
                return maxi;
            
            while(left <= right && power >= tokens[left]) {
                power -= tokens[left++];
                score++;
            }
            maxi = max(score, maxi);
            if(score <= 0) 
                return maxi;
            while(left <= right && power < tokens[left] ) {
                power += tokens[right--];
                score--;
            }
            
        }
        return maxi;
    }
};