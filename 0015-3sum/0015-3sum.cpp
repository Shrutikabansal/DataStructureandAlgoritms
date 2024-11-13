class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector< int> > ans;

        sort(nums.begin(), nums.end());

        int i,j,k;

        for(i=0;i<n;i++){
            j = i+1;
            k = n-1;

            if (i>0 && nums[i] == nums[i-1]){
                continue;
            }


            while(j<k){

                int totalSum = nums[i] + nums[j] + nums[k];

                if (totalSum > 0){
                    k--;
                }else if (totalSum < 0){
                    j++;
                }else{
                    ans.push_back({nums[i],nums[j],nums[k] });
                    j++;

                    while (nums[j] == nums[j-1] && j<k){
                        j++;
                    } 

                }
            }
        }

        return ans;
    }
};