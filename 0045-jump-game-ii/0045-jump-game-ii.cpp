class Solution {
public:
    int jump(vector<int>& nums) {

        int n = nums.size();

        int start = 0, end = 0;
        int jumping =0;

        for(end = 0;end <n-1;){
            int ending = 0;
            for(int i = start;i<=end;i++){
                ending = max(ending, i+nums[i]);
            }
            jumping =jumping+1;
            start = end+1;
            end = ending;


        }

        return jumping;


        
    }
};