class Solution {
public:
    int countSubstrings(string s) {
               int n = s.size();
        vector< vector<bool> > dp(n, vector<bool>(n,false));
        int i,j;
        string ans;

        for(i=0;i<n;i++){
            dp[i][i] = 1;
        }

        for(i=0;i<n-1;i++){
            if (s[i] == s[i+1]){
                dp[i][i+1] = 1;
            }
        }

        for (int k = 3; k <= n; ++k) {
        for ( i = 0; i < n - k + 1; ++i) {
             j = i + k - 1;

            if (dp[i + 1][j - 1] && s[i] == s[j]) {
                dp[i][j] = 1;

               
            }
        }
    }
    int count =0;
    for (i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(dp[i][j] == 1){
                count++;
            }
        }
    }


    return count;
    }
};