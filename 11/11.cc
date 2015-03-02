/*
 * 1： 假设i，j 为可以围城最大面颊，则在j的右侧不应该有j' > j,同理，在i的左侧不应该有i' > i，
 *     否则 假设存在j' > j,并且 i，j围城的面积为C， 则i，j'围城的面积 C' = min(height[i],height[j']) * (j' - i)
 *     因为 (j' - i) > (j - i) && min(height[i],height[j']) >= min (height[i],height[j]) ，所以C' > C ,这与C 是最大面积相矛盾
 * 2:  所以对于i，j区间内围城的最大面积i'，j' 满足 height[i'] > height[i] && height[j'] > height[j]
 *     可以从i，j两边向中间进行逼近，找到围城面积最大的之
*/
class Solution {
public:
    int maxArea(vector<int> &height) {

        if (height.size() == 0 || height.size() == 1)
            return 0;

        int i = 0, j = height.size() - 1;
        int maxarea = 0;
        while (i < j) {
            int area = (j - i) * min(height[i],height[j]);
            if (area > maxarea)
                maxarea = area;

            if (height[i] < height[j])
            {
                int k = i;                          
                while (k < j && height[k] <= height[i]) //注意： 必须是小于等于  否则缺少等于的话 第一的比较与自身比较就不满足
                    k ++;

                i = k;
            }
            else {
                int k = j;
                while (k > i && height[k] <= height[j])
                    k --;

                j = k;
            }
        }
        return maxarea;
    }
};
