// 1
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        permute(ans, nums, 0);
        return ans;
    }

    void permute(vector<vector<int>>& ans, vector<int>& perm, int begin)
    {
        if (begin == perm.size()) {
            ans.push_back(perm);
            return;
        }

        for (int i=begin; i<perm.size(); i++) {
            if (i!=begin && perm[i] == perm[begin]) continue;
            swap(perm[i], perm[begin]);
            permute(ans, perm, begin+1);
            swap(perm[i], perm[begin]);
        }

    }
};


// 2
It is obvious that N numbers has N! permutations .

Here I assume an empty vector also has one permutation. It seems OJ didn't check the empty input case. Well, it doesn't matter.

class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        // Add an empty vector as the base case (empty input)
        vector<vector<int> > permutations(1, vector<int>());
        // Algrithm description:
        //  Insert the current number in different spaces of previous permutations
        for (vector<int>::size_type index = 0; index != num.size(); ++index)
        {
            vector<vector<int> > subPermutations(permutations);
            permutations.clear();
            for (vector<vector<int> >::size_type i = 0; i != subPermutations.size(); ++i)
            {
                for (int offset = 0; offset != subPermutations[i].size()+1; ++offset)
                {
                    vector<int> temp(subPermutations[i]);
                    temp.insert(temp.begin() + offset, num[index]);
                    permutations.push_back(temp);
                }
            }
        }
        return permutations;
    }
};


// 3
// method 1: standard backtracing solution
vector<vector<int> > permute(vector<int> &num) {
    vector<vector<int> > ans;
    permutation(num, 0, ans);
    return ans;
}

void permutation(vector<int> &num, int begin, vector<vector<int> > &ans) {
    if (begin >= num.size()) {
        ans.push_back(num);
        return;
    }

    // every number chosen to be the begin once
    for (int i = begin; i < num.size(); ++i) {
        swap(num[begin], num[i]);
        permutation(num, begin+1, ans);
        swap(num[begin], num[i]);
    }
}

// method 2: using next_permutation to iterate all the permutaions
vector<vector<int> > permute(vector<int> &num) {
    vector<vector<int> > ans;
    sort(num.begin(), num.end());
    ans.push_back(num);

    while(next_permutation(num.begin(), num.end()))
        ans.push_back(num);
    return ans;
}

// method 3: recursive dfs
vector<vector<int> > permute(vector<int> &num) {
    vector<vector<int> > ans;
    dfs(num, ans);
    return ans;
}

void dfs(vector<int> &num, vector<vector<int>> &ans) {
    if (num.size() == 1) {
        vector<int> tmp(num.begin(), num.end());
        ans.push_back(tmp);
        return;
    }

    vector<vector<int> > ans1;
    vector<int> num1(num.begin()+1, num.end());
    dfs(num1, ans);

    for(int i = 0; i < ans.size(); ++i) {
        for(int j = 0; j <= ans[i].size(); ++j) {
            vector<int> tmp = ans[i];
            tmp.insert(tmp.begin()+j, num[0]);
            ans1.push_back(tmp);
        }
    }

    ans = ans1;
}
