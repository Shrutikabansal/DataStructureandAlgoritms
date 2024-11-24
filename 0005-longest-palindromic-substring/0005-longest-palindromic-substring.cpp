class Solution {
public:
    string longestPalindrome(string s) {

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


        // for(i=0;i<n;i++){
        //     for(j=0;j<n;j++){
        //         cout<< dp[i][j]<< " ";
        //     }
        //     cout<<endl;
        // }

        int maxLength = 0;
        for (i=0;i<n;i++){
            for(j=i;j<n;j++){
                if(dp[i][j] && maxLength < j-i+1){
                    maxLength = max(maxLength, j-i+1);
                    ans = s.substr(i,maxLength);
                    // cout<< ans<< " "<< maxLength<<  " " << i << " " << j <<endl;
                }

            }
        }

        return ans;

        
        
    }
};