class Solution {
public:
    int findMin(vector<int>& nums) {

        int n = nums.size();
        if(nums[0] < nums[n-1]){
            return nums[0];
        }

        int left = 0, right = n-1, mid = (left+right)/2;

        while(left<=right){
            mid = (left+right)/2;
            if(nums[mid] >= nums[right]){
                left = mid+1;
            }else{
                right = mid;
            }
        }
        return nums[mid];
        
    }
};