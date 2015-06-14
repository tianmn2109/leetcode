// 1
class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<vector<int> > result;
        sort(num.begin(), num.end());
        combHelper(num, 0, num.size(), target, vector<int>(), result);
        return result;
    }

    void combHelper(vector<int>& a, int start, int n, int target, 
    vector<int> cur_vec, vector<vector<int> >& result) {

        if (target == 0) {
            result.push_back(cur_vec);
            return;
        }
        int i = start;
        while(i < n  && target-a[i] >= 0) {
            // NOTE : this condition helps neglecting making identical sets
            //  this is the catch of this question
            if (i == start || a[i] != a[i-1]) {
                cur_vec.push_back(a[i]);
                combHelper(a, i+1, n, target-a[i], cur_vec, result);
                cur_vec.pop_back();
            }
            i++;
        }
    }
};


// 2
class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        vector<int> result;
        dfs(num, result, target, 0, 0);
        return r;
    }

private:
    void dfs(vector<int> &num, vector<int>& result, int target, int sum, int beg) {
        if (sum == target) {
            r.push_back(result);
            return;
        }
        if (sum > target || beg == num.size()) 
            return;

        result.push_back(num[beg]);
        dfs(num, result, target, sum + num[beg], beg+1);
        result.pop_back();

        int end = beg;
        while(end+1<num.size() && num[end]==num[end+1]) end++;
        dfs(num, result, target, sum, end+1);
    }

    vector<vector<int> > r;
};


// 3
class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
         vector<int> path;
         vector<vector<int> > ret;
         sort(candidates.begin(), candidates.end());
         search(candidates, 0, target, path, ret);
         return ret;
    }

    void search(vector<int> & candidates, int idx, int target, vector<int> & path, 
    vector<vector<int> > & ret)
    {
        if(target == 0)
        {
            ret.push_back(path);
            return;
        }
        if(idx == candidates.size() ||  target < candidates[idx])
            return;
        path.push_back(candidates[idx]);
        search(candidates, idx + 1, target - candidates[idx] , path, ret);
        path.pop_back();
        idx++;
        while(idx< candidates.size() && candidates[idx] == candidates[idx -1]) 
            idx++;
        search(candidates, idx, target , path, ret);

    }
};


// 4
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> path;
        sort(candidates.begin(),candidates.end());
        dfs(result,candidates,path,0,target);
        return result;
    }
private:
    void dfs(vector<vector<int>> &result,vector<int>& candidates,vector<int> path,int current,int target){
        if(!path.empty()&&target==0){
            result.push_back(path);
            return;
        }
        if(current<candidates.size()){
            int tmp = -1;//start from 0 and 1
            for(;current<candidates.size();current++){

                if(candidates[current]==tmp)
                    continue;
                if(target-candidates[current]<0)
                    return;

                tmp = candidates[current];
                path.push_back(candidates[current]);
                dfs(result,candidates,path,current+1,target-candidates[current]);
                path.pop_back();
            }
        }
    }
};



// 5
At the beginning, I stuck on this problem. After careful thought, I think this kind of backtracking contains a iterative component and a resursive component so I'd like to give more details to help beginners save time. The revursive component tries the elements after the current one and also tries duplicate elements. So we can get correct answer for cases like [1 1] 2. The iterative component checks duplicate combinations and skip it if it is. So we can get correct answer for cases like [1 1 1] 2.

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) 
    {
        vector<vector<int>> res;
        sort(num.begin(),num.end());
        vector<int> local;
        findCombination(res, 0, target, local, num);
        return res;
    }
    void findCombination(vector<vector<int>>& res, const int order, const int target, vector<int>& local, const vector<int>& num)
    {
        if(target==0)
        {
            res.push_back(local);
            return;
        }
        else
        {
            for(int i = order;i<num.size();i++) // iterative component
            {
                if(num[i]>target) return;
                if(i&&num[i]==num[i-1]&&i>order) continue; // check duplicate combination
                local.push_back(num[i]),
                findCombination(res,i+1,target-num[i],local,num); // recursive componenet
                local.pop_back();
            }
        }
    }
};


