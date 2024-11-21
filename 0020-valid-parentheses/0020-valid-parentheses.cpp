class Solution {
public:
    bool isValid(string s) {

        stack<char> st;
        for(int i = 0;i<s.size();i++){
            if(s[i] == '(' || s[i] == '{' ||s[i] == '[' ){
                st.push(s[i]);
            }
            if(s[i] == ']'){
                cout<< " here"<< endl;
                if(st.empty() || st.top() != '['  ){
                                    cout<< " here"<< endl;

                    st.pop();
                    return false;
                }else{
                                        st.pop();

                }
            }

            if(s[i] == '}'){
                 if(st.empty() || st.top() != '{'  ){
                    st.pop();
                    return false;
                }else{
                                        st.pop();

                }
            }

            if(s[i] == ')'){
                 if(st.empty() || st.top() != '('  ){
                    st.pop();
                    return false;
                }else{
                                        st.pop();

                }

            }
        }
        if(!st.empty()){
            return false;
        }

        // for(int i = s.size()-1;i>=0  && !st.empty();i--){
        //     if(s[i] == ']'){
        //         cout<< " here"<< endl;
        //         if(st.empty() || st.top() != '['  ){
        //                             cout<< " here"<< endl;

        //             st.pop();
        //             return false;
        //         }
        //     }

        //     if(s[i] == '}'){
        //          if(st.empty() || st.top() != '{'  ){
        //             st.pop();
        //             return false;
        //         }
        //     }

        //     if(s[i] == ')'){
        //          if(st.empty() || st.top() != '('  ){
        //             st.pop();
        //             return false;
        //         }

        //     }

        // }

        return true;
        
    }
};