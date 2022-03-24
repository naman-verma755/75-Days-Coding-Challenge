class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int sizeOfArray = digits.size();
        
        
        int carry = 1;   //first increment the value of digit and then take carry of digit.
        vector<int>ans; // Declare resultant array
        for(int itr = sizeOfArray-1; itr >= 0; itr--)
        {
            int newNum = digits[itr] + carry;
            if(newNum > 9)
            {
                ans.push_back(0);
                carry = 1;
            }
            else
            {
                ans.push_back(newNum);
                carry = 0;
            }
        }
        if(carry == 1)        
            ans.push_back(1);   
        reverse(ans.begin(), ans.end());
        
        return ans;
        
    }
};