class Solution {
public:
    bool canJump(vector<int>& nums) {

        int n = nums.size();
        if(n == 1){
            return true;
        }

        if (nums[0] == 0){
            return false;
        }



        vector<int> jump(n, INT_MAX);
        jump[0] = 0;

        int i,j;

        for(i=1;i<n;i++){
            for(j=0;j<i;j++){
                if(i<=j+nums[j] && jump[j]!=INT_MAX){
                    jump[i] = min(jump[i], jump[j]+1);
                }
            }
        }

        if(jump[n-1]!=INT_MAX){
            return true;
        }
        return false;

        
    }
};