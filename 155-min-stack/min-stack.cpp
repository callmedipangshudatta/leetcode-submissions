class MinStack {
public:
    stack<int> minStk;
    stack<int> Stk;
    MinStack() {
        
    }
    
    void push(int value) {
        Stk.push(value);
        if(minStk.empty() || value <= minStk.top()){
            minStk.push(value);
        }
    }
    
    void pop() {
      if(minStk.top() == Stk.top()){
        minStk.pop();
      }
      Stk.pop();
    }
    
    int top() {
        return Stk.top();
    }
    
    int getMin() {
        return minStk.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */