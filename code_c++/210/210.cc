class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int> > graph(numCourses, vector<int>());
        for (int i = 0; i < prerequisites.size(); i ++)
            graph[prerequisites[i].second].push_back(prerequisites[i].first);
        int in[numCourses] = {0};
        for (int i = 0; i < prerequisites.size(); i ++)
            in[prerequisites[i].first] ++;
        vector<int> result;
        queue<int> q;
        for (int i = 0; i < numCourses; i ++)
            if (in[i] == 0)
                q.push(i);
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int i = 0; i < graph[cur].size(); i ++) {
                in[graph[cur][i]] --;
                if (in[graph[cur][i]] == 0)
                    q.push(graph[cur][i]);
            }
            result.push_back(cur);
        }
        return result.size() == numCourses ? result : (result.clear(), result);
    }
};
