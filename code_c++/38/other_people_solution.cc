// 1
We backtrack from successful searches as well because they are saved at the leafs of recursion tree
class Solution {
public:

    void search(vector<int>& num, int next, vector<int>& pSol, int target, vector<vector<int> >& result)
    {
        if(target == 0)
        {
            result.push_back(pSol);
            return;
        }

        if(next == num.size() || target - num[next] < 0)
            return;

        pSol.push_back(num[next]);
        search(num, next, pSol, target - num[next], result);
        pSol.pop_back();

        search(num, next + 1, pSol, target, result);
    }


    vector<vector<int> > combinationSum(vector<int> &num, int target) 
    {
        vector<vector<int> > result;
        sort(num.begin(), num.end());
        vector<int> pSol;
        search(num, 0, pSol, target, result);
        return result;    
    }
};


// 2  We backtrack from successful searches as well because they are saved at the leafs of recursion tree
class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector< vector< vector<int> > > combinations(target + 1, vector<vector<int>>());
        combinations[0].push_back(vector<int>());
        for (auto& score : candidates)
            for (int j = score; j <= target; j++)
                if (combinations[j - score].size() > 0) {
                    auto tmp = combinations[j - score];
                    for (auto& s : tmp)
                        s.push_back(score);
                    combinations[j].insert(combinations[j].end(), tmp.begin(), tmp.end());
                }
        auto ret = combinations[target];
        for (int i = 0; i < ret.size(); i++)
            sort(ret[i].begin(), ret[i].end());
        return ret;
    }
};


// 3
Accepted 16ms c++ solution use backtracking for Combination Sum:

class Solution {
public:
    std::vector<std::vector<int> > combinationSum(std::vector<int> &candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        std::vector<std::vector<int> > res;
        std::vector<int> combination;
        combinationSum(candidates, target, res, combination, 0);
        return res;
    }
private:
    void combinationSum(std::vector<int> &candidates, int target, std::vector<std::vector<int> > &res, std::vector<int> &combination, int begin) {
        if  (!target) {
            res.push_back(combination);
            return;
        }
        for (int i = begin; i != candidates.size() && target >= candidates[i]; ++i) {
            combination.push_back(candidates[i]);
            combinationSum(candidates, target - candidates[i], res, combination, i);
            combination.pop_back();
        }
    }
};

Accepted 12ms c++ solution use backtracking for Combination Sum II:

class Solution {
public:
    std::vector<std::vector<int> > combinationSum2(std::vector<int> &candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        std::vector<std::vector<int> > res;
        std::vector<int> combination;
        combinationSum2(candidates, target, res, combination, 0);
        return res;
    }
private:
    void combinationSum2(std::vector<int> &candidates, int target, std::vector<std::vector<int> > &res, std::vector<int> &combination, int begin) {
        if  (!target) {
            res.push_back(combination);
            return;
        }
        for (int i = begin; i != candidates.size() && target >= candidates[i]; ++i)
            if (i == begin || candidates[i] != candidates[i - 1]) {
                combination.push_back(candidates[i]);
                combinationSum2(candidates, target - candidates[i], res, combination, i + 1);
                combination.pop_back();
            }
    }
};

Accepted 0ms c++ solution use backtracking for Combination Sum III:

class Solution {
public:
    std::vector<std::vector<int> > combinationSum3(int k, int n) {
        std::vector<std::vector<int> > res;
        std::vector<int> combination;
        combinationSum3(n, res, combination, 1, k);
        return res;
    }
private:
    void combinationSum3(int target, std::vector<std::vector<int> > &res, std::vector<int> &combination, int begin, int need) {
        if (!target) {
            res.push_back(combination);
            return;
        }
        else if (!need)
            return;
        for (int i = begin; i != 10 && target >= i * need + need * (need - 1) / 2; ++i) {
            combination.push_back(i);
            combinationSum3(target - i, res, combination, i + 1, need - 1);
            combination.pop_back();
        }
    }
};

// 4
recursive solution use dfs

class Solution {
    public:
        vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
            vector<vector<int> > ret;
            vector<int> path;
            sort( candidates.begin(), candidates.end() );  // ensure non-descending
            dfs( candidates, target, 0, path, ret );
            return ret;
        }
        // depth-first 
        void dfs(vector<int> &candidates, int target, int idx,
        vector<int> path, vector<vector<int> > &ret)
        {
            for( int i = idx; i < candidates.size(); i++ )    // begin with idx, avoid duplicated
            {
                if( target == candidates[i] )
                {
                    vector<int> tmp = path;
                    tmp.push_back( candidates[i] );
                    ret.push_back(tmp);
                }
                if( target - candidates[i] >= candidates[0] )
                {
                    vector<int> tmp = path;
                    tmp.push_back( candidates[i] );
                    dfs( candidates, target-candidates[i], i, tmp, ret );
                }
            }
        }
    };



