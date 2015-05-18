class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> f1(ratings.size(), 1);
        vector<int> f2(ratings.size(), 1);
        for (int i = 1; i< ratings.size(); i ++)
            if (ratings[i] > ratings[i - 1])
                f1[i] = f1[i - 1] + 1;
        for (int i = ratings.size() - 2; i >= 0; i --)
            if (ratings[i] > ratings[i + 1])
                f2[i] = f2[i + 1] + 1;
        int minCandy = 0;
        for (int i = 0; i < ratings.size(); i ++)
            minCandy += max(f1[i], f2[i]);
        return minCandy;
    }
};
