class MinStack {
public:
    stack<int> stk;
    stack<int> minStk;
    void push(int x) {
        stk.push(x);
        if (minStk.empty() || minStk.top() >= x)
            minStk.push(x);
    }
    void pop() {
        if (minStk.top() == stk.top())
            minStk.pop();
        stk.pop();
    }
    int top() {
        return stk.top();
    }
    int getMin() {
        return minStk.top();
    }
};
