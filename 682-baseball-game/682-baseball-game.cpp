class Solution {
public:
    int calPoints(vector<string>& ops) {
        
        vector<int>Util;
        for(int i = 0; i < ops.size(); i++) {
            if(ops[i] == "+") {
                int sum = (Util[Util.size()-1]+Util[Util.size()-2]);
                Util.push_back(sum);
            }
            else if(ops[i] == "D") {
                Util.push_back(2*Util[Util.size()-1]);
            }
            else if(ops[i] == "C") {
                Util.pop_back();
            }
            else
                Util.push_back(stoi(ops[i]));
        }
        int sum =0 ;
        for(int i = 0; i < Util.size(); i++)
        {
            sum += Util[i];
        }
        return sum;
        
    }
};