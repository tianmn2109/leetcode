The problem has a nice structure that backtracking naturally fits in. The structure is, given a starting position idx, we search from idx till the end of the string s.length() - 1. Once we reach a position i such that the sub-string from idx to i (s.substr(idx, i - idx + 1)) is a palindrome, we add it to a temporary solution sol. Then we recursive call the same function to process the remaining sub-string. Once we reach the end of the string, we add sol into a record of the possible solutions res.

Then, backtracking happens! Remember that at position i, we find s.substr(idx, i - idx + 1) to be a palindrome and we immediately add it to sol. It is obvious that there may be some position j such that j > i and s.substr(idx, j - idx + 1) is also a palindrome. So we need to return to the state of starting from position i and finding the next palindrome position after i. And we simply need to pop s.substr(idx, i - idx + 1) out of the sol to make things work.

Putting these together, we can write down the following code, which is self-explanatory.

void getPartition(string s, int idx, vector<string>& sol, vector<vector<string> >& res) {
    if (idx == s.length()) {
        res.push_back(sol);
        return;
    }
    for (int i = idx; i < s.length(); i++) {
        int l = idx, r = i;
        bool isPalindrome = true;
        while (l < r)
            if (s[l++] != s[r--]) {
                isPalindrome = false;
                break;
            }
        if (isPalindrome) {
            sol.push_back(s.substr(idx, i - idx + 1));
            getPartition(s, i + 1, sol, res);
            sol.pop_back();
        }
    }
}
vector<vector<string> > partition(string s) {
    vector<vector<string> >  res;
    vector<string> sol;
    getPartition(s, 0, sol, res);
    return res;
}
Well, personally I think backtracking is not very intuitive and makes people crazy to follow the algorithm step by step. I now treat it by breaking it down into several pieces (where to start, where to recursive call, how to recover original status and how to record all these things). But sometimes I think to write a correct backtracking code still requires some experience. If you have any nice suggestion about how to deal with backtracking more systematically and intuitively, please let me know. Thank you!
