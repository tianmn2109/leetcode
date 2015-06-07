class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
       vector<string> ret;
       int i = 0;
       while (i < words.size()) {
           int beg = i;
           int size = 0;
           while (i < words.size() ) {    // get the length of the current line
               if (words[i] == "") {
                   i ++;
                   continue;
               }
               int newSize = size == 0 ? words[i].size() : size + 1 + words[i].size();
               if (newSize <= maxWidth)
                    size = newSize;
                else
                    break;
                i ++;
           }
           int everySpace = 0;
           int leftSpace = maxWidth;
           int j = beg;
           while (j < i) {
               leftSpace -= words[j ++].size();
           }
           if ((i - 1 - beg) != 0 && i != words.size()) {
               everySpace = leftSpace / (i - 1 - beg);
               leftSpace = leftSpace - (i - 1 - beg) * everySpace;
           }
           else {
               everySpace = 0;
           }
           string temp = "";
           for (int j = beg; j < i; j ++) {
               if (j == beg)
                  temp += words[j];
               else {
                   for (int k = 0; k < everySpace; k ++)
                        temp += " ";
                    if (leftSpace > 0) {
                        temp += " ";
                        leftSpace --;
                    }
                    temp += words[j];
               }
           }
           while (leftSpace --)
                temp += " ";
           ret.push_back(temp);
       }
       return ret;
    }
};
