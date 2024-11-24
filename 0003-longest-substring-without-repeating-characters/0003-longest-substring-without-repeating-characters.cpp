class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n = s.size();
        int i = 0, j =1;
        if (n==0){
            return 0;
        }

        set<int>st;
        st.insert(s[i]);

        int maxLength = 1;

        while (i<j && i<n && j<n){
            if(st.count(s[j]) > 0){
                st.erase(s[i]);
                i ++ ;
                st.insert(s[i]);
                if (i == j){
                    j = j+1;
                }
                continue;
            }else{
                st.insert(s[j]);
                maxLength = max(maxLength, j-i+1);
                j++;
            }



        }
        
        return maxLength;
    }
};