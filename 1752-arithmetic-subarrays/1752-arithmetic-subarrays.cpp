class Solution {
public:

    bool checkUtil(vector<int> &a){

        int n = a.size();
        int mini = INT_MAX;
        int maxi = INT_MIN;
        set<int> s;

        for(int i=0;i<n;i++){
            mini = min(a[i], mini);
            maxi = max(a[i], maxi);
            s.insert(a[i]);
        }


        int diff  = (maxi - mini )/(n-1);

        if((maxi - mini )%(n-1) != 0){
            return false;
        }

        if (diff == 0){
            return true;
        }

        while(mini <= maxi){
            if(s.find(mini) == s.end()){
                return false;
            }

            mini = mini + diff;
        }

        return true;
    }


    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {

        int n = nums.size();
        int m = l.size();
        vector<bool> v;
        for (int i=0;i<m;i++){
            vector<int> a(nums.begin()+l[i], nums.begin()+r[i]+1);
            v.push_back(checkUtil(a));
        }

        return v;
        
    }
};