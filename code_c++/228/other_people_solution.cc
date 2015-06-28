// 1
 vector<string> summaryRanges(vector<int>& nums) {
    int i = 0, size = nums.size();
    vector<string> result; 
    while(i < size){
        int j = 1; 
        while(i + j < size && nums[i + j] - nums[i] == j) ++j;
        result.push_back(j <= 1 ? to_string(nums[i]) : to_string(nums[i]) + "->" + to_string(nums[i + j - 1]));
        i += j; 
    }
    return result; 
}

// 2
Solution 1

Go through the numbers, i0 is the index where the current range starts and i is the current index. At the end of a range, recognized by i == nums.size()-1 || nums[i+1] > nums[i]+1, add the range to the output and update i0 for the next range.

vector<string> summaryRanges(vector<int>& nums) {
    vector<string> ranges;
    for (int i=0, i0=0; i<nums.size(); i++) {
        if (i == nums.size()-1 || nums[i+1] > nums[i]+1) {
            ranges.push_back(to_string(nums[i0]));
            if (i > i0) ranges.back() += "->" + to_string(nums[i]);
            i0 = i + 1;
        }
    }
    return ranges;
}
Solution 2

I saw lestrois's solution and then wrote that approach myself in C++. For each range, find its end and then add the range to the output.

vector<string> summaryRanges(vector<int>& nums) {
    vector<string> ranges;
    for (int i=0, i0=0; i<nums.size(); i0=++i) {
        while (i+1<nums.size() && nums[i+1]==nums[i]+1) i++;
        ranges.push_back(to_string(nums[i0]));
        if (i > i0) ranges.back() += "->" + to_string(nums[i]);
    }
    return ranges;
}
