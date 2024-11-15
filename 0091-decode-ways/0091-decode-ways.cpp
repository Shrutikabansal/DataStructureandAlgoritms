class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if(s[0] == '0'){
            return 0;
        }

        vector<int>dp(n+1,0);

        dp[0] = dp[1] = 1;
        int i;

        for(i=1;i<n;i++){
            int first = s[i] - '0';
            int second = stoi(s.substr(i-1, 2));

            // cout<< first << " "<< second;

            if(first>=1 && first <=9){
                dp[i+1] += dp[i];
            }
            if(second>=10 && second <= 26){
                dp[i+1] += dp[i-1];
            }
        }

        return dp[n];
        
    }
};