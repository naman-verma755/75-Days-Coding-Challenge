class Solution {
public:
    
void func(int i, vector<int>&a, vector<int>&db, vector<vector<int>>&ans, int target, int n)
{
	if(i>=n || target < 0)
	return;
	
	if(target == 0)
	{
		
		ans.push_back(db);
		return;
	}
	db.push_back(a[i]);
	
	func(i,a,db, ans, target-a[i],n);
	db.pop_back();
	func(i+1,a,db, ans,target,n);
	
	
	
}
    vector<vector<int>> combinationSum(vector<int>& a, int target) {
       sort(a.begin(),a.end());
        int n = a.size();
        vector<vector<int>>ans;
	vector<int>db;
	func(0,a,db,ans,target,n);
        return ans;
        
    }
};