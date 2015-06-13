// 1
 // travel all the words combinations to maintain a window
    // there are wl(word len) times travel
    // each time, n/wl words, mostly 2 times travel for each word
    // one left side of the window, the other right side of the window
    // so, time complexity O(wl * 2 * N/wl) = O(2N)
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> ans;
        int n = S.size(), cnt = L.size();
        if (n <= 0 || cnt <= 0) return ans;

        // init word occurence
        unordered_map<string, int> dict;
        for (int i = 0; i < cnt; ++i) dict[L[i]]++;

        // travel all sub string combinations
        int wl = L[0].size();
        for (int i = 0; i < wl; ++i) {
            int left = i, count = 0;
            unordered_map<string, int> tdict;
            for (int j = i; j <= n - wl; j += wl) {
                string str = S.substr(j, wl);
                // a valid word, accumulate results
                if (dict.count(str)) {
                    tdict[str]++;
                    if (tdict[str] <= dict[str]) 
                        count++;
                    else {
                        // a more word, advance the window left side possiablly
                        while (tdict[str] > dict[str]) {
                            string str1 = S.substr(left, wl);
                            tdict[str1]--;
                            if (tdict[str1] < dict[str1]) count--;
                            left += wl;
                        }
                    }
                    // come to a result
                    if (count == cnt) {
                        ans.push_back(left);
                        // advance one word
                        tdict[S.substr(left, wl)]--;
                        count--;
                        left += wl;
                    }
                }
                // not a valid word, reset all vars
                else {
                    tdict.clear();
                    count = 0;
                    left = j + wl;
                }
            }
        }

        return ans;
    }



// 2
class Solution {
// The general idea:
// Construct a hash function f for L, f: vector<string> -> int, 
// Then use the return value of f to check whether a substring is a concatenation 
// of all words in L.
// f has two levels, the first level is a hash function f1 for every single word in L.
// f1 : string -> double
// So with f1, L is converted into a vector of float numbers
// Then another hash function f2 is defined to convert a vector of doubles into a single int.
// Finally f(L) := f2(f1(L))
// To obtain lower complexity, we require f1 and f2 can be computed through moving window.
// The following corner case also needs to be considered:
// f2(f1(["ab", "cd"])) != f2(f1(["ac", "bd"]))
// There are many possible options for f2 and f1. 
// The following code only shows one possibility (probably not the best), 
// f2 is the function "hash" in the class,
// f1([a1, a2, ... , an]) := int( decimal_part(log(a1) + log(a2) + ... + log(an)) * 1000000000 )
public:
    // The complexity of this function is O(nW).
    double hash(double f, double code[], string &word) {
        double result = 0.;
        for (auto &c : word) result = result * f + code[c];
        return result;
    }
    vector<int> findSubstring(string S, vector<string> &L) {
        uniform_real_distribution<double> unif(0., 1.);
        default_random_engine seed;
        double code[128];
        for (auto &d : code) d = unif(seed);
        double f = unif(seed) / 5. + 0.8;
        double value = 0;

        // The complexity of the following for loop is O(L.size( ) * nW).
        for (auto &str : L) value += log(hash(f, code, str));

        int unit = 1e9;
        int key = (value-floor(value))*unit;
        int nS = S.size(), nL = L.size(), nW = L[0].size();
        double fn = pow(f, nW-1.);
        vector<int> result;
        if (nS < nW) return result;
        vector<double> values(nS-nW+1);
        string word(S.begin(), S.begin()+nW);
        values[0] = hash(f, code, word);

        // Use a moving window to hash every word with length nW in S to a float number, 
        // which is stored in vector values[]
        // The complexity of this step is O(nS).
        for (int i=1; i<=nS-nW; ++i) values[i] = (values[i-1] - code[S[i-1]]*fn)*f + code[S[i+nW-1]];

        // This for loop will run nW times, each iteration has a complexity O(nS/nW)
        // So the overall complexity is O(nW * (nS / nW)) = O(nS)
        for (int i=0; i<nW; ++i) {
            int j0=i, j1=i, k=0;
            double sum = 0.;

            // Use a moving window to hash every L.size() continuous words with length nW in S.
            // This while loop will terminate within nS/nW iterations since the increasement of j1 is nW,
            // So the complexity of this while loop is O(nS / nW).
            while(j1<=nS-nW) {
                sum += log(values[j1]);
                ++k;
                j1 += nW;
                if (k==nL) {
                    int key1 = (sum-floor(sum)) * unit;
                    if (key1==key) result.push_back(j0);
                    sum -= log(values[j0]);
                    --k;
                    j0 += nW;
                }
            }
        }
        return result;
    }
};



// 3
I would like share my linear solution with HashTable and Queue with runtime only 71ms. The Queue is used to store the last appearance position of the first word of that type. You need to update the Queue each time.

vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> res;
        if (L.size() == 0) return res;
        if (S.size() == 0) return res;
        int wordLen = L[0].size();
        if (S.size() < wordLen) return res;

        unordered_map<string, queue<int> > wordhash; // word and appearing positions.
        unordered_map<string, queue<int> >::iterator it;
        queue<int> Q;
        Q.push(-1);
        for (int i = 0; i<L.size(); ++i) {
            it = wordhash.find(L[i]);
            if (it == wordhash.end()) {
                wordhash[L[i]] = Q;
            } else {
                it->second.push(-1);
            }
        }
        unordered_map<string, queue<int> > temp = wordhash;
        for (int i = 0; i<wordLen; ++i) {
            int currWordCnt = 0;
            wordhash = temp;
            for (int index = i; index<=S.size()-wordLen; index += wordLen) {
                it = wordhash.find(S.substr(index, wordLen));
                if (it == wordhash.end()) {
                    currWordCnt = 0;
                } else {
                    int lastPos = it->second.front();
                    if (lastPos == -1) {
                        currWordCnt++;
                    } else if (currWordCnt*wordLen < index-lastPos) {
                        currWordCnt++;
                    } else {
                        currWordCnt = (index-lastPos)/wordLen;
                    }
                    it->second.pop();
                    it->second.push(index);
                    if (currWordCnt == L.size()) {
                        res.push_back(index-wordLen*(L.size()-1));
                    }
                }
            }
        }
        return res;
    }


// 4
The idea is quite simple. Just use a trie tree to accelerate testing whether a substring is valid. The value of each TrieNode is used to deal with duplication and to mark whether the word is used before.

      static class TrieNode {
           int value = 0;
           Map<Character, TrieNode> children = new HashMap<Character, TrieNode>();
       }

       TrieNode trie;

    // build a trie tree
    public List<Integer> findSubstring(String S, String[] L) {
        trie = buildTrie(L);
        int length = getTotalLength(L);
        List<Integer> result = new LinkedList<Integer>();
        for (int i = 0; i < S.length() - length + 1; i++) {
            if (isSubString(S, i, i + length))
                result.add(i);
        }
        return result;
    }

    private int getTotalLength(String[] L) {
        int sum = 0;
        for (String l : L)
            sum += l.length();
        return sum;
    }

    private TrieNode buildTrie(String[] L) {
        TrieNode root = new TrieNode();
        for (String l : L)
            addWord(root, l);
        return root;
    }

    private void addWord(TrieNode root, String s) {
        TrieNode node = root;
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            TrieNode next = node.children.get(c);
            if (next == null) {
                next = new TrieNode();
                node.children.put(c, next);
            }
            node = next;
        }
        node.value++;
    }

    private boolean isSubString(String S, int start, int end) {
        if (start == end)
            return true;
        // search in the trie tree
        TrieNode node = trie;
        for (int i = start; i < end; i++) {
            char c = S.charAt(i);
            if (node.children.get(c) == null)
                return false;
            node = node.children.get(c);
            if (node.value > 0) {  // leaf & can be used
                node.value--; // mark as used
                if (isSubString(S, i + 1, end)) {
                    node.value++; // mark as unused
                    return true;
                }
                node.value++; // mark as unused
            }
        }
        return false;
    }



