class Stack {
public:
    queue<int> q;
    // Push element x onto stack.
    void push(int x) {
        queue<int> temp;
        while (!q.empty()) {
            temp.push(q.front());
            q.pop();
        }
        q.push(x);
        while (!temp.empty()) {
            q.push(temp.front());
            temp.pop();
        }
    }
    // Removes the element on top of the stack.
    void pop(void) {
        q.pop();
    }
    // Get the top element.
    int top(void) {
        return q.front();
    }
    // Return whether the stack is empty.
    bool empty(void) {
        return q.empty();
    }
};
