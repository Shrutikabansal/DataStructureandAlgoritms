class Solution {
public:

    // we can do this solution with dp & trie
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool>dp(n+1, false);
        dp[0] = true;

        
        for(int i=1;i<=n;i++){
            for(auto word: wordDict){
                int wordSize = word.size();
                int startP = i - wordSize;
                // cout<< s.substr(startP, wordSize) << " "<< word<< endl;
                if(startP>=0 && dp[startP] && (s.substr(startP, wordSize) == word)){
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};