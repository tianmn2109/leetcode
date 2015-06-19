// 1
vector<string> anagrams(vector<string> &strs) {
    vector<string> result;
    vector<string> sortedStrs = strs;
    unordered_map<string, vector<int>> map;
    for(int i = 0; i < strs.size(); i++){
        sort(sortedStrs[i].begin(), sortedStrs[i].end());
        map[sortedStrs[i]].push_back(i);
    }
    for(auto it = map.begin(); it != map.end(); it++){
        if(it->second.size() > 1){
            for(int i = 0; i < it->second.size(); i++){
                result.push_back(strs[it->second[i]]);
            }
        }
    }
    return result;
}

Here is basic idea for this problem.

First, get a copy of "strs". Let's name this copy "sortedStrs".

Second, sort all strings in "sortedStrs".

And we have a hash map unordered_map<string, vector<int>> map.

Every string in "sortedStrs" will be recorded in this hash map with its position.

In the second loop, we traverse this hash map. And find each value of which size is larger than 1. Then find the original string in "strs".

Done.

