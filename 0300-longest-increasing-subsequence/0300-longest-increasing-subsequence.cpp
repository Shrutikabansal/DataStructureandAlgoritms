class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();
        int i,j;
        int lis[n];

        lis[0]=1;

        for(i=1;i<n;i++){
            lis[i] = 1;
            for(j=0;j<i;j++){
                if(nums[i] > nums[j] && lis[i] < lis[j]+1){
                    lis[i] = lis[j]+1;
                }
            }
        }

        return *max_element(lis, lis+n);
        
    }
};