class Solution {
public:
    string simplifyPath(string path) {
       vector<string> v;
       vector<string> ret;
       string str = "";
       int i = 0;
       if (path.size() == 0)
           return str;

       while (path[i] != '\0') {
           if (path[i] == '/')
           {
               i ++;
               continue;
           }

           string s = "";
           s += path[i ++];
           while (path[i] != '\0' && path[i] != '/')
               s += path[i ++];
           v.push_back(s);
       }

       for (int i = 0; i < v.size(); i ++) {
           if (v[i] == "..") {
               if (!ret.empty())
                   ret.pop_back();
           }
           else if (v[i] == ".")
               continue;
           else 
                ret.push_back(v[i]);

       }

       for (int i = 0; i < ret.size(); i ++)
           str = str + "/" + ret[i];

        if (str == "") 
            str = "/";

        return str;
    }
};
