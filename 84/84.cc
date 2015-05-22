class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        int maxArea = 0;
       height.push_back(0);
       stack<int> stk;
       for (int i = 0; i < height.size();)
            if (stk.empty() || height[stk.top()] < height[i])
                    stk.push(i ++);
            else {
                int temp = stk.top();
                stk.pop();
                int width = stk.empty() ? i : i - stk.top() - 1;
                maxArea = max(maxArea, height[temp] * width);
            }
        return maxArea;
    }
};
