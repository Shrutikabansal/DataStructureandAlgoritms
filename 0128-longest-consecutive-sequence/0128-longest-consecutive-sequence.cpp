class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int, int>mp;

        for(int i=0;i<nums.size();i++){
            mp[nums[i]] = i;
        }

        int last =INT_MIN;
        int length = 0;
        int maxLength = 0;

        // for(auto it = mp.begin(); it !=mp.end();it++){
        //  last = it->first;
        //  length = 1;
        //     break;

        //     // cout<< it->first << " "<< it->second << endl;
        // }

        // auto it = mp.begin();

       for(auto  it =mp.begin(); it !=mp.end();it++){
        if(it->first == last+1){
            length = length +1;
            last =  it->first;
        }else{
            length = 1;
            last =  it->first;
            // cout<< it->first <<endl;
        }
        maxLength = max(length, maxLength);



       }

        return maxLength;
    }
};