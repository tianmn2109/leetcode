// 1
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int m1[256] = {0}, m2[256] = {0}, n = s.size();
        for (int i = 0; i < n; ++i) {
            if (m1[s[i]] != m2[t[i]]) return false;
            m1[s[i]] = i + 1;
            m2[t[i]] = i + 1;
        }
        return true;
    }
};

// 2
bool isIsomorphic(char* s, char* t) {
    char charArrS[256] = { 0 };
    char charArrT[256] = { 0 };
    int i = 0;
    while (s[i] !=0)
    {
        if (charArrS[s[i]] == 0 && charArrT[t[i]] == 0)
        {
            charArrS[s[i]] = t[i];
            charArrT[t[i]] = s[i];
        }
        else
        if (charArrS[s[i]] != t[i] || charArrT[t[i]] != s[i])
            return false;
        i++;
    }

    return true;
}

// 3
class Solution {
public:
    bool isIsomorphic(string s, string t) 
    {
        const size_t n = s.size();
        if ( n != t.size())
            return false;

        unsigned char forward_map[256] = {}, reverse_map[256] = {};

        for ( int i=0; i < n; ++i)
        {
            unsigned char c1 = s[i];
            unsigned char c2 = t[i];

            if ( forward_map[c1] && forward_map[c1] != c2)
                return false;

            if ( reverse_map[c2] && reverse_map[c2] != c1)
                return false;

            forward_map[c1] = c2;
            reverse_map[c2] = c1;
        }

        return true;
    }
};
