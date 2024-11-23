class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<string, vector<int> > mp;
        for(int i =0;i< strs.size();i++){
            string data = strs[i];
            sort(data.begin(), data.end());
            mp[data].push_back(i);
        }

        // for(auto it = mp.begin(); it != mp.end(); it++){
        //     cout<< it->first << " ";

        //     for(int j = 0; j < (it->second).size(); j++){
        //         cout<<  (it->second)[j]<< " ";
        //     }
        //     cout<< endl;
        // }

        for (auto it = mp.begin(); it != mp.end(); it++){
            vector<string> v;
            vector<int> temp = it->second;
            for(int j = 0; j < (it->second).size(); j++){
                v.push_back(strs[it->second[j]]);
            }
            ans.push_back(v);

        }

        return ans;
        
    }
};