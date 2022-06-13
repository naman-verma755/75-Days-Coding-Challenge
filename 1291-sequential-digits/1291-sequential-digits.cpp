class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        
        vector<int>ans;
        string s = "123456789";
        for(int window = 2; window <= 9; window++) {
            int i = 0;
            while(i + window <= 9) {
                
                int num = stoi(s.substr(i, window));
                if(low <= num && num <= high) 
                    ans.push_back(num);
                i++;
            }
        }
        return ans;
        
    }
};