// 1
class Solution {
public:
int findMin(vector<int> &num) {
    int start = 0;
    int end = num.size()-1;
    int mid;
    while(start<end){
        if(num[start]<num[end])
        break;
        mid = start+(end-start)/2;
        if(num[mid]>num[end]){
            start = mid+1;
        }
        else if(num[mid]==num[end]){
            start++;
            end--;
        }
        else
        end= mid;
    }
    return num[start];
 }
};

// 2
class Solution {
public:
    int findMin(vector<int> &num) {
        int lo = 0;
        int hi = num.size() - 1;
        int mid = 0;

        while(lo < hi) {
            mid = lo + (hi - lo) / 2;

            if (num[mid] > num[hi]) {
                lo = mid + 1;
            }
            else if (num[mid] < num[hi]) {
                hi = mid;
            }
            else { // when num[mid] and num[hi] are same
                hi--;
            }
        }
        return num[lo];
    }
};
