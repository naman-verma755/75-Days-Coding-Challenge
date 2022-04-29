class Solution {
public:
    void dfs(string email, set<string>&visited, vector<string>&mergedAccount, map<string, vector<string>>&adjacent) {
        
        visited.insert(email);
        
        mergedAccount.push_back(email);
        
        for(string emails : adjacent[email]) {
            
            if(visited.find(emails) == visited.end()) {
               
                dfs(emails, visited, mergedAccount, adjacent);
                
            }
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        
        map<string, vector<string>>adjacent;
        set<string>visited;
        
        for(vector<string>&account : accounts) {
            string firstEmail = account[1];
            
            for(int j = 1; j < account.size(); j++ ) {
                
                adjacent[firstEmail].push_back(account[j]);
                adjacent[account[j]].push_back(firstEmail);
            }
        }
        vector<vector<string>>mergedAccounts;
        for(vector<string>&account: accounts ) {
            
            string email = account[0];
            string firstEmail = account[1];
           
            if(visited.find(firstEmail) == visited.end()) {
                vector<string>mergedAccount;
                mergedAccount.push_back(email);
                dfs(firstEmail, visited, mergedAccount, adjacent);
                
                sort(mergedAccount.begin()+1, mergedAccount.end());
                mergedAccounts.push_back(mergedAccount);
            }
        }
        return mergedAccounts;
    }
};