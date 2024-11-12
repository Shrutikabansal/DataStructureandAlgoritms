class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int i;

        int left, right, maxProd;
        left = 1; right = 1;
        maxProd = INT_MIN;

        for (i=0;i<n;i++){
            if (left == 0){
                left = 1;
            }
            if (right == 0){
                right = 1;
            }
            left = left * nums[i];
            right = right * nums[n-i-1];
            maxProd = max(left, max(right, maxProd));
        }

        return maxProd;
    }
};