class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char, int> mp;

        int n = s.size();
        int i =0 ,j, maxFreq;
        int ans = 0;

        for(j=0;j<n;j++){
            mp[s[j]] ++;
            maxFreq = max(maxFreq, mp[s[j]]);
            if(j-i+1-maxFreq > k){
                mp[s[i]]--;
                ++i;
            }else{
            ans = max(ans, j-i+1);

            }



        }
        return ans;
    }
};