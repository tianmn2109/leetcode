/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        int maxNum = 0;
        for (int i = 0; i < points.size(); i ++) {
            int samePoint = 0;
            map<double, int> m;
            int inif = 0;
            int maxOther = 0;
            for (int j = i; j < points.size(); j ++) {
                int tempMax = 0;
                if (points[i].x == points[j].x && points[i].y == points[j].y) {
                    samePoint ++;
                }
                else if (points[i].x == points[j].x) {
                    inif ++;
                    tempMax = inif;
                }
                else {
                    double ratio = 0.0 + (double)(points[i].y - points[j].y) / (points[i].x - points[j].x); //first convert to duoble type, otherwise the result will be integer
                    if (m.find(ratio) != m.end())
                        m[ratio] ++;
                    else
                        m[ratio] = 1;
                    tempMax = m[ratio];
                }
                if (tempMax > maxOther)
                    maxOther = tempMax;
            }
            if (samePoint + maxOther > maxNum)
                maxNum = samePoint + maxOther;
        }
        return maxNum;
    }
};
