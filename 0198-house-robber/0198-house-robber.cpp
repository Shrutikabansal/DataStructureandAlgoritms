class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n==1)
            return nums[0];

        int i,j;

        int first = nums[0];
        int second = max(nums[0], nums[1]);

        for(i=2;i<n;i++){
            int third = max(second, first+nums[i]);
            first = second;
            second = third;
        }

        return second;
    }
};