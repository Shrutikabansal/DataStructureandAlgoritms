class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size(), i;

        set<int>s;
        for(i=0;i<n;i++){
            if(s.count(nums[i]) > 0){
                
                return true;
            }
                s.insert(nums[i]);
            
        }

 
        return false;

    }
};