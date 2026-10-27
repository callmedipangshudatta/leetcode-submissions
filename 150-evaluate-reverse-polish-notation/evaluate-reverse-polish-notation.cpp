class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string token : tokens){
            if(token == "+"){
                int firstNum = st.top();
                st.pop();
                int secondNum = st.top();
                st.pop();
                st.push(firstNum + secondNum);
            }
            else if(token == "-"){
                int firstNum = st.top();
                st.pop();
                int secondNum = st.top();
                st.pop();
                st.push(secondNum - firstNum);
            }else if(token == "*"){
                int firstNum = st.top();
                st.pop();
                int secondNum = st.top();
                st.pop();
                st.push(firstNum * secondNum);
            }else if(token == "/"){
                int firstNum = st.top();
                st.pop();
                int secondNum = st.top();
                st.pop();
                st.push(secondNum / firstNum);
            }else{
                st.push(stoi(token));
            }
        }
        return st.top();
    }
};