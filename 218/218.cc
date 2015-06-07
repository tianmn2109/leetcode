class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int> > result;
        vector<pair<int, int> > v;
        for (int i = 0; i < buildings.size(); i ++) {
            v.push_back(make_pair(buildings[i][0], -buildings[i][2]));
            v.push_back(make_pair(buildings[i][1], buildings[i][2]));
        }
        multiset<int> h;
        h.insert(0);
        sort(v.begin(), v.end());
        int prevHeight = 0, curHeight = 0;
        for (int i = 0; i < v.size(); i ++) {
            int x = v[i].first;
            int y = v[i].second;
            if (y < 0)
                h.insert(-y);
            else
                h.erase(h.find(y));
            curHeight = *h.rbegin();
            if (prevHeight != curHeight) {
                result.push_back(make_pair(x, curHeight));
                prevHeight = curHeight;
            }
        }
        return result;
    }
};
