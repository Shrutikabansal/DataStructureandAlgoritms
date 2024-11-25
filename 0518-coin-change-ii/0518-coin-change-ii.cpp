class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size(),i,j;
        vector< vector<unsigned long long int> > dp (n+1, vector<unsigned long long int> (amount+1, 0));

        sort(coins.begin(), coins.end());
        for(i=0;i<=n;i++){
            dp[i][0] = 1;
        }

        for(i=1;i<=n;i++){
            for(j=1;j<=amount;j++){
                if(coins[i-1] > j){
                    dp[i][j] = dp[i-1][j];
                }else{
                    dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];
                }
            }
        }

        return dp[n][amount];
        
    }
};