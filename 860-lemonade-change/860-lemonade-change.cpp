class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        
        int arr[21] = {};
        // sort(bills.begin(), bills.end());
        
        for(int currency: bills) {
            
            if(currency == 5) 
                arr[5]++;
            
            if(currency == 10) {
                if(arr[5] > 0)
                    arr[5]--,arr[10]++;
                else
                    return false;
            }
            if(currency == 20) {
                if(arr[5] > 0 && arr[10] > 0)
                    arr[5]--,arr[10]--;
                else if(arr[5] > 2)
                    arr[5] -= 3;
                else
                    return false;
            }
            
        }
        return true;
    }
};