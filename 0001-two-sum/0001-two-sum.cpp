class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_set<int>s;
        vector<int>v;
        int i,j;
        int n=nums.size();
        int temp;
        for(i=0;i<n;i++)
        {
            temp=target-nums[i];
            if(s.find(temp)!=s.end())
            {
                v.push_back(i);
                auto it=find(nums.begin(), nums.end(), temp);
                v.push_back(it-nums.begin());
             //   cout<<it-v.begin()+1;
                sort(v.begin(),v.end());
               break;
            }
            else
                s.insert(nums[i]);
                
        }
        return v;
    }
};