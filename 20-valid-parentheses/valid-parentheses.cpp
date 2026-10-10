class Solution {
public:
    bool isValid(string s) {
        if(s == ""){
            return false;
        }
        stack<char> st;
        for(char c : s){
            if(c == '(' || c == '[' || c == '{' ){
                st.push(c);
            }else{
                if(st.empty()){
                    return false;
                }
                char top = st.top(); 
                st.pop();
                if((top == '[' && c != ']') || (top == '{' && c != '}') || (top == '(' && c != ')') ){
                    return false;
                }
            }
        }
        return st.empty();
        
    }
};