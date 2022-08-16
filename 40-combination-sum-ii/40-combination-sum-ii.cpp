class Solution {
public:
    
    void findUniqueCombinations(int index, int target, vector<int>&candidates, vector<int>&v, set<vector<int>>&st) {
        
        if(target == 0)
        {
           st.insert(v);
            return;
        }
        
        if(index == candidates.size() || target < 0)
            return;
        
        
        
        v.push_back(candidates[index]);
        findUniqueCombinations(index+1, target-candidates[index], candidates, v, st);
        v.pop_back();
        int prev = candidates[index];
        int i = index+1;
        while(i < candidates.size() && candidates[i] == prev) {
            i++;
        }
        findUniqueCombinations(i, target, candidates, v, st);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        sort(candidates.begin(), candidates.end());
        vector<vector<int>>ans;
        set<vector<int>>st;
        vector<int>v;
        // vector<vector<int>>dp(candidates.size()+1, vector<int>(target, -1));
        findUniqueCombinations(0, target, candidates, v, st);
        for(auto it : st)
            ans.push_back(it);
        return ans;
        
        
//         1 1 2 5 6 7 10
            
//             1 2 2 2 5
            
            
    }
};