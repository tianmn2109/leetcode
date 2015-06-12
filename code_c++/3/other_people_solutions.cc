// 1  Dp O(n)

/**
 * Solution (DP, O(n)):
 * 
 * Assume L[i] = s[m...i], denotes the longest substring without repeating
 * characters that ends up at s[i], and we keep a hashmap for every
 * characters between m ... i, while storing <character, index> in the
 * hashmap.
 * We know that each character will appear only once.
 * Then to find s[i+1]:
 * 1) if s[i+1] does not appear in hashmap
 *    we can just add s[i+1] to hash map. and L[i+1] = s[m...i+1]
 * 2) if s[i+1] exists in hashmap, and the hashmap value (the index) is k
 *    let m = max(m, k), then L[i+1] = s[m...i+1], we also need to update
 *    entry in hashmap to mark the latest occurency of s[i+1].
 * 
 * Since we scan the string for only once, and the 'm' will also move from
 * beginning to end for at most once. Overall complexity is O(n).
 *
 * If characters are all in ASCII, we could use array to mimic hashmap.
 */

int lengthOfLongestSubstring(string s) {
    // for ASCII char sequence, use this as a hashmap
    vector<int> charIndex(256, -1);
    int longest = 0, m = 0;

    for (int i = 0; i < s.length(); i++) {
        m = max(charIndex[s[i]] + 1, m);    // automatically takes care of -1 case
        charIndex[s[i]] = i;
        longest = max(longest, i - m + 1);
    }

    return longest;
}


// 2 Dp

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int last[256];
        int maxSize = 0;
        memset(last, -1, sizeof(last));
        int beginPos = 0;
        for (int lastPos = 0; lastPos < s.size(); lastPos++) {
           if (last[s[lastPos]] < beginPos) {
               maxSize = max(maxSize, lastPos-beginPos+1);
           } else {
               beginPos = last[s[lastPos]] + 1;
           }
           last[s[lastPos]] = lastPos;
        }

        return maxSize;
    }
};
