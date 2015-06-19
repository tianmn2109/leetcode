// 1
C++ also have getline which acts like Java's split. I guess the code can comment itself.

string simplifyPath(string path) {
    string res, tmp;
    vector<string> stk;
    stringstream ss(path);
    while(getline(ss,tmp,'/')) {
        if (tmp == "" or tmp == ".") continue;
        if (tmp == ".." and !stk.empty()) stk.pop_back();
        else if (tmp != "..") stk.push_back(tmp);
    }
    for(auto str : stk) res += "/"+str;
    return res.empty() ? "/" : res;
}


// 2

    traverse the string to record each folder name.
    two special cases:

a.double dot:pop one.

b.single dot: do nothing (don`t push it).

string simplifyPath(string path) {
    vector<string>   nameVect;
    string name;

    path.push_back('/');
    for(int i=0;i<path.size();i++){
        if(path[i]=='/'){
            if(name.size()==0)continue;
            if(name==".."){     //special case 1：double dot，pop dir
                 if(nameVect.size()>0)nameVect.pop_back();
            }else if(name=="."){//special case 2:singel dot，don`t push
            }else{          
                nameVect.push_back(name);
            }
            name.clear();
        }else{
            name.push_back(path[i]);//record the name
        }
    }

    string result;
    if(nameVect.empty())return "/";
    for(int i=0;i<nameVect.size();i++){
        result.append("/"+nameVect[i]);
    }
    return result;
}


