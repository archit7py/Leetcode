class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>st;
        stack<char>st1;
        for(int i = 0; i<s.size(); i++){
            if(s[i] == '#'){
                if(!st.empty()){
                    st.pop();
                }
                
            }
            else{
                st.push(s[i]);
            }
            
        }
        for(int j = 0; j<t.size(); j++){
            if(t[j] == '#'){
                if(!st1.empty()){
                    st1.pop();
                }
                
            }
            else{
                st1.push(t[j]);
            }
        }
        if(st == st1){
            return true;
        }
        return false;
        
    }
};