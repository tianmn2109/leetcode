public class Solution {
public int canCompleteCircuit(int[] gas, int[] cost) {
    for(int i = 0; i < gas.length; i++) {
        gas[i] -= cost[i];
    }
    int sum = 0;
    int result = 0;
    int n = gas.length;
    for(int i = 0; i < n * 2 - 1; i++) {
        sum += gas[i % n];
        if(sum < 0) {
            result = i + 1;
            if(result >= n) {
                return -1;
            }
            sum = 0;
        }
    }
    return result;
}
