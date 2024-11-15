class Solution {
public:
    bool canJump(vector<int>& nums) {

       int n = nums.size();
       int target = n-1;
       int i;

       for(i=n-2;i>=0;i--){
        if(i+nums[i] >= target){
            target = i;
        }
       }

       return target ==0;
    }
};