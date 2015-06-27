// 1 This is a concise solution using stringstream to format string into int.

int compareVersion(string version1, string version2) {
    for(auto& w : version1) if (w == '.') w=' ';
    for(auto& w : version2) if (w == '.') w=' ';
    istringstream s1(version1), s2(version2);
    while(1) {
        int n1,n2;
        if (not(s1 >> n1) ) n1 = 0;
        if (not(s2 >> n2) ) n2 = 0;
        if (not s1 and not s2) return 0;
        if (n1<n2) return -1;
        if (n1>n2) return 1;
    }
}



Here's the algorithm: Assumption is that the strings are properly formatted so no checking. Valid strings are 123, 01, 123.01.5.16 I extracted the string into a C style char array for speed. Scan both the strings one sub-version at a time in a loop if result is still 0 and one (or both) of the strings still have characters left to parse. So basically, once the result is 1 or -1 we don't need further parsing. I'm using strtol so that we can pick each sub-version number and move the scan pointer to the "." preceding next sub-version number. If one of the strings is done before the other (example: 1.0 and 1) then make sure to the sub-version of finished string to 0.

int compareVersion(string version1, string version2) {
    int result = 0;
    char *vStr1 = (char*) version1.c_str();
    char *vStr2 = (char*) version2.c_str();

    while (result == 0 && (*vStr1 != '\0' || *vStr2 != '\0')) {
        long v1 = *vStr1 == '\0' ? 0 : strtol(vStr1, &vStr1, 10);
        long v2 = *vStr2 == '\0' ? 0 : strtol(vStr2, &vStr2, 10);
        if (v1 > v2) result = 1;
        else if (v2 > v1) result = -1;
        else {
            if (*vStr1 != '\0') vStr1++;
            if (*vStr2 != '\0') vStr2++;
        }
    }        

    return result;
}
solutio
