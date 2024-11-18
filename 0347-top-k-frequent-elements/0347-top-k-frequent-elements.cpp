class Solution {
public:

    // bool compareF(pair<int, int> p1, pair<int, int> p2){
    //     if(p1.second == p2.second)
    //         return p1.first > p2.first;
        
    //     return p1.second > p2.second;
    // }


struct compareF {
    bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) {
       if(p1.second == p2.second)
            return p1.first < p2.first;
        
        return p1.second < p2.second;
    }
};

    vector<int> topKFrequent(vector<int>& nums, int k) {

        int n = nums.size();
        int i;

        map<int, int>mp;

        for(i=0;i<n;i++){
            if(mp.find(nums[i]) == mp.end())
                mp[nums[i]] = 1;
            else
                mp[nums[i]] += 1;
        }

        priority_queue< pair<int, int> , vector<pair<int, int> >, compareF >pq(mp.begin(), mp.end());

        // for(auto it = mp.begin(); it!= mp.end(); it++){
        //     pq.push({it->first, it->second});
        // }


        // auto pqCopy = pq;
        // while (!pqCopy.empty()) {
        //     auto topElement = pqCopy.top();
        //     std::cout << "(" << topElement.first << ", " << topElement.second << ")\n";
        //     pqCopy.pop(); // Safe to pop from the copy
        // }



        vector<int>v;
        while(!pq.empty() && k > 0){
            v.push_back(pq.top().first);
            pq.pop();
            k--;
        }
    

        // for(i=0;i<v.size();i++){
        //     cout<< v[i] << " ";
        // }

        // cout<< endl;

        return v;
        
    }
};