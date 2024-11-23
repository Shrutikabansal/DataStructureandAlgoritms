class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int>mpS;
        map<char, int>mpT;

        if (s.size() != t.size()){
            return false;
        }

        for (int i = 0; i < s.size(); i++){
            mpS[s[i]] ++ ;
        }

        for (int i = 0; i < t.size(); i++){
            mpT[t[i]] ++ ;
        }

        if (mpS.size() != mpT.size()){
            return false;
        }

        for ( auto it1 = mpS.begin() , it2 = mpT.begin() ; it1 != mpS.end() && it2 != mpT.end(); it1++, it2++){
            if (it1->first != it2->first || it1->second != it2->second){
                return false;
            }
        }
        return true;
    }
};