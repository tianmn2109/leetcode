// 1
The main idea is to store the substring as int in map to bypass the memory limits.

There are only four possible character A, C, G, and T, but I want to use 3 bits per letter instead of 2.

Why? It's easier to code.

A is 0x41, C is 0x43, G is 0x47, T is 0x54. Still don't see it? Let me write it in octal.

A is 0101, C is 0103, G is 0107, T is 0124. The last digit in octal are different for all four letters. That's all we need!

We can simply use s[i] & 7 to get the last digit which are just the last 3 bits, it's much easier than lookup table or switch or a bunch of if and else, right?

We don't really need to generate the substring from the int. While counting the number of occurrences, we can push the substring into result as soon as the count becomes 2, so there won't be any duplicates in the result.

vector<string> findRepeatedDnaSequences(string s) {
    unordered_map<int, int> m;
    vector<string> r;
    int t = 0, i = 0, ss = s.size();
    while (i < 9)
        t = t << 3 | s[i++] & 7;
    while (i < ss)
        if (m[t = t << 3 & 0x3FFFFFFF | s[i++] & 7]++ == 1)
            r.push_back(s.substr(i - 10, 10));
    return r;
}

// 2
This is a solution which may apply to all kinds of strings (not only strings with ATCG charactors). It is a little slow and also not very short. I just want to show another way to solve this problem.

The idea is simple... First, it is easy to write out this codes:

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        set<string> c, r;
        for (int i = 0, l = s.length(); i < l - 9; i++) {
            string sub = s.substr(i, 10);
            if (!c.insert(sub).second) {
                r.insert(sub);
            }
        }
        return vector<string>(r.begin(), r.end());
    }
};
But it got MLE instead of AC. So, what we should do is reducing the memory usage. One way to do this is storing only the pointer for starter of string, so the original string could be reused. After some changes the code looks like this:

class Solution {
    template <int N>
    class NChar {
    public:
        const char* val;
        NChar(const char* val) : val(val) {}
        bool operator<(const NChar<N>& that) const {
            return memcmp(val, that.val, N) < 0;
        }
        operator string() const {
            return string(val, val + N);
        }
    };
    typedef NChar<10> TenChar;
public:
    vector<string> findRepeatedDnaSequences(string s) {
        set<TenChar> c, r;
        const char* cs = s.c_str();
        for (int i = 0, l = s.length(); i < l - 9; i++) {
            TenChar sub(cs + i);
            if (!c.insert(sub).second) {
                r.insert(sub);
            }
        }
        return vector<string>(r.begin(), r.end());
    }
};
This code could get AC. Maybe it is much slower than the version which use integer to compare. But I think the performance should be acceptable.
