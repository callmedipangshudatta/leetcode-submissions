class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string ch: tokens){
            if(ch == "+"){
                int firstNum = st.top();
                st.pop();
                int secondNum = st.top();
                st.pop();
                st.push(firstNum + secondNum);
            }
            else if(ch == "-"){
                int firstNum = st.top();
                st.pop();
                int secondNum = st.top();
                st.pop();
                st.push(secondNum - firstNum);
            }else if(ch == "*"){
                int firstNum = st.top();
                st.pop();
                int secondNum = st.top();
                st.pop();
                st.push(firstNum * secondNum);
            }else if(ch == "/"){
                int firstNum = st.top();
                st.pop();
                int secondNum = st.top();
                st.pop();
                st.push(secondNum / firstNum);
            }else{
                st.push(stoi(ch));
            }
        }
        return st.top();
    }
};