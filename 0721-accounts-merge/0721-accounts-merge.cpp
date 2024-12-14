class Solution {
public:

    map<string, vector<string> > adj;


    void dfs(string firstEmail, vector<string> &mergeAcount, set<string> &s){
        s.insert(firstEmail);

        mergeAcount.push_back(firstEmail);

        for(auto adjTrace : adj[firstEmail]){
            if(s.find(adjTrace) == s.end()){
                dfs(adjTrace, mergeAcount, s);
            }
        }

    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        int n = accounts.size();
        for(int i = 0;i <n ;i++){
            int subList = accounts[i].size();
            for(int j = 2;j<subList; j++){
                adj[accounts[i][1]].push_back(accounts[i][j]);
                adj[accounts[i][j]].push_back(accounts[i][1]);
            }
        }


        set<string> vis;
        vector<vector<string>> ans;

        for (auto accountList : accounts){
            if(vis.find(accountList[1]) == vis.end()){
                vector<string> mergeAccount;

                // push name
                mergeAccount.push_back(accountList[0]);
                dfs(accountList[1], mergeAccount, vis);
                sort(mergeAccount.begin()+1, mergeAccount.end());
                ans.push_back(mergeAccount);
            }

        }
        

        return ans;
        
    }
};