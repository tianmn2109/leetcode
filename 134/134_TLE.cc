class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (gas.size() == 0)
            return -1;
        if (gas.size() == 1)
            return 0;
        for (int i = 0 ;i < gas.size(); i ++) {
            if (gas[i] - cost[i] < 0)
                continue;
            int capacity = gas[i] - cost[i];
            int j = (i + 1) % (gas.size());
            while (j != i) {
                capacity = gas[j] + capacity - cost[j];
                if (capacity < 0)
                    break;
                j = (j + 1) % (gas.size());
            }
            if (j == i)
                return i;
        }
        return -1;
    }
};
