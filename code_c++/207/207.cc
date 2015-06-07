class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int> > graph(numCourses);
        for (int i = 0; i < prerequisites.size(); i ++)
            graph[prerequisites[i].second].push_back(prerequisites[i].first);
        bool visited[numCourses];
        bool marked[numCourses];
        memset(visited, 0, numCourses * sizeof(bool));
        memset(marked, 0, numCourses * sizeof(bool));
        for (int i = 0; i < numCourses; i ++)
            if (dfs(graph, visited, marked, i))
                return false;
        return true;
    }
    bool dfs(vector<vector<int> > &graph, bool *visited, bool *marked, int current) {
        if (visited[current])
            return true;
        if (marked[current])
            return false;
        visited[current] = true;
        for (int i = 0; i < graph[current].size(); i ++) {
            if (dfs(graph, visited, marked, graph[current][i]))
                return true;
        }
        marked[current] = true;
        visited[current] = false;
        return false;
    }
};
