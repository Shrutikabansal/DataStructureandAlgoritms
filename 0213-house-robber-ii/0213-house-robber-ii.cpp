class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n==1)
            return nums[0];

        int i,j;

        int first1 = nums[0];
        int second1 = max(nums[0], nums[1]);

        for(i=2;i<n-1;i++){
            int third1 = max(second1, first1+nums[i]);
            first1 = second1;
            second1 = third1;
        }

        if (n==2){
            return second1;
        }

        // cout<< second1<< endl;

        int first2 = nums[1];
        int second2 = max(nums[1], nums[2]);

        for(i=3;i<n;i++){
            int third2 = max(second2, first2+nums[i]);
            first2 = second2;
            second2 = third2;
        }

        // cout<< second1;
        // cout<< second2;

        return max(second1, second2);

    }
};