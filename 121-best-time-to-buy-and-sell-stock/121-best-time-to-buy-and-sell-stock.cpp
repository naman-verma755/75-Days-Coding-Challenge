class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        
        int size = prices.size();
        
        int profit = 0;
        int prevSmallElement = prices[0];
        for(int i = 1; i < size; i++) {
            if(prices[i] > prevSmallElement) {                    //If current element is greater than previous small element;
                profit = max(profit,(prices[i]-prevSmallElement)); //then storing maximum profit 
            }
            else if(prices[i] < prevSmallElement)  // else updated our previous small element
                prevSmallElement = prices[i];    
        }
        return profit;
        
    }
};