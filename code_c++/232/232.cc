class Queue {
public:
    stack<int> stk;
    // Push element x to the back of queue.
    void push(int x) {
        stack<int> temp;
        while (!stk.empty()) {
            temp.push(stk.top());
            stk.pop();
        }
        temp.push(x);
        while (!temp.empty()) {
            stk.push(temp.top());
            temp.pop();
        }
    }

    // Removes the element from in front of queue.
    void pop(void) {
        stk.pop();
    }

    // Get the front element.
    int peek(void) {
        return stk.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return stk.empty();
    }
};
