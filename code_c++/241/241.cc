class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> ret;
        for (int i = 0; i < input.size(); i ++) {
            if (input[i] == '+' || input[i] == '-' || input[i] == '*') {
                vector<int> left = diffWaysToCompute(input.substr(0, i));
                vector<int> right = diffWaysToCompute(input.substr(i + 1));
                for (auto n1 : left) {
                    for (auto n2: right) {
                        switch(input[i]) {
                            case '+':
                                    ret.push_back(n1 + n2);
                                    break;
                            case '-':
                                    ret.push_back(n1 - n2);
                                    break;
                            case '*':
                                    ret.push_back(n1 * n2);
                                    break;
                            default:
                                    break;
                        }
                    }
                }
            }
        }
        if (ret.empty()) {
            ret.push_back(atoi(input.c_str()));
        }
        return ret;
    }
};
