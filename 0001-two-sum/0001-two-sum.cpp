class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int n = nums.size(), i;
        map<int, int> mp;
        vector<int>v;

        for(i=0;i<n;i++){
            if(mp.find(target - nums[i]) == mp.end()){
                mp[nums[i]] = i;
            }else{
                v.push_back(mp[target - nums[i]]);
                v.push_back(i);
                break;
            }
        }

        return v;



    }
};