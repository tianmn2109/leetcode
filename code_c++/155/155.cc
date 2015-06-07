class MinStack {
public:
    stack<int> stk;
    stack<int> minStk;
    void push(int x) {
        stk.push(x);
        if (minStk.empty() || minStk.top() > x)
            minStk.push(x);
        else
            minStk.push(minStk.top());
    }
    void pop() {
        stk.pop();
        minStk.pop();
    }
    int top() {
        return stk.top();
    }
    int getMin() {
        return minStk.top();
    }
};
