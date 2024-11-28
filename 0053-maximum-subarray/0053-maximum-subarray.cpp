class Solution {
public:
    int maxSubArray(vector<int>& a) {
        int ans = a[0];
        int maxEnd = a[0];

        for(int i =1;i<a.size();i++){
            maxEnd = max(maxEnd+a[i], a[i]);
            ans = max(maxEnd, ans);
        }

        return ans;
        
    }
};