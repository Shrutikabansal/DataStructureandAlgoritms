class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefix(n,1);
        vector<int> suffix(n,1);
        vector<int> answer(n,0);
        int i;

        for (i=1;i<n;i++){
            prefix[i] = prefix[i-1]*nums[i-1];
        }

        for (i=n-2;i>=0;i--){
            suffix[i] = suffix[i+1]*nums[i+1];
        }

        for (i=0;i<n;i++){
            answer[i] =  suffix[i]*prefix[i];
        }

        return answer;
        
    }
};