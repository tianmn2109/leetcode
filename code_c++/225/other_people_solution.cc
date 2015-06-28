// with omly one queue
class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        int len = nums.size();
        nums.push(x);
        for (int i = 0; i != len; ++i) {
            nums.push(nums.front());
            nums.pop();
        }
    }
    // Removes the element on top of the stack.
    void pop() {
        nums.pop();
    }
    // Get the top element.
    int top() {
        return nums.front();
    }
    // Return whether the stack is empty.
    bool empty() {
        return nums.empty();
    }
private:
    std::queue<int> nums;
};
