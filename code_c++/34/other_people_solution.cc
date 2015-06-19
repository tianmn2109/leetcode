// 1 is not this problem's answer.
class Solution {
public:
    int search(int A[], int n, int target) {
        int lo=0,hi=n-1;
        // find the index of the smallest value using binary search.
        // Loop will terminate since mid < hi, and lo or hi will shrink by at least 1.
        // Proof by contradiction that mid < hi: if mid==hi, then lo==hi and loop would have been terminated.
        while(lo<hi){
            int mid=(lo+hi)/2;
            if(A[mid]>A[hi]) lo=mid+1;
            else hi=mid;
        }
        // lo==hi is the index of the smallest value and also the number of places rotated.
        int rot=lo;
        lo=0;hi=n-1;
        // The usual binary search and accounting for rotation.
        while(lo<=hi){
            int mid=(lo+hi)/2;
            int realmid=(mid+rot)%n;
            if(A[realmid]==target)return realmid;
            if(A[realmid]<target)lo=mid+1;
            else hi=mid-1;
        }
        return -1;
    }
};



// 2
The problem can be simply broken down as two binary searches for the begining and end of the range, respectively:

First let's find the left boundary of the range. We initialize the range to [i=0, j=n-1]. In each step, calculate the middle element [mid = (i+j)/2]. Now according to the relative value of A[mid] to target, there are three possibilities:

    If A[mid] < target, then the range must begins on the right of mid (hence i = mid+1 for the next iteration)
    If A[mid] > target, it means the range must begins on the left of mid (j = mid-1)
    If A[mid] = target, then the range must begins on the left of or at mid (j= mid)

Since we would move the search range to the same side for case 2 and 3, we might as well merge them as one single case so that less code is needed:

2*. If A[mid] <= target, j = mid;

Surprisingly, 1 and 2* are the only logic you need to put in loop while (i < j). When the while loop terminates, the value of i/j is where the start of the range is. Why?

No matter what the sequence originally is, as we narrow down the search range, eventually we will be at a situation where there are only two elements in the search range. Suppose our target is 5, then we have only 7 possible cases:

case 1: [5 7] (A[i] = target < A[j])
case 2: [5 3] (A[i] = target > A[j])
case 3: [5 5] (A[i] = target = A[j])
case 4: [3 5] (A[j] = target > A[i])
case 5: [3 7] (A[i] < target < A[j])
case 6: [3 4] (A[i] < A[j] < target)
case 7: [6 7] (target < A[i] < A[j])

For case 1, 2 and 3, if we follow the above rule, since mid = i => A[mid] = target in these cases, then we would set j = mid. Now the loop terminates and i and j both point to the first 5.

For case 4, since A[mid] < target, then set i = mid+1. The loop terminates and both i and j point to 5.

For all other cases, by the time the loop terminates, A[i] is not equal to 5. So we can easily know 5 is not in the sequence if the comparison fails.

In conclusion, when the loop terminates, if A[i]==target, then i is the left boundary of the range; otherwise, just return -1;

For the right of the range, we can use a similar idea. Again we can come up with several rules:

    If A[mid] > target, then the range must begins on the left of mid (j = mid-1)
    If A[mid] < target, then the range must begins on the right of mid (hence i = mid+1 for the next iteration)
    If A[mid] = target, then the range must begins on the right of or at mid (i= mid)

Again, we can merge condition 2 and 3 into:

2* If A[mid] <= target, then i = mid;

However, the terminate condition on longer works this time. Consider the following case:

[5 7], target = 5

Now A[mid] = 5, then according to rule 2, we set i = mid. This practically does nothing because i is already equal to mid. As a result, the search range is not moved at all!

The solution is by using a small trick: instead of calculating mid as mid = (i+j)/2, we now do:

mid = (i+j)/2+1

Why does this trick work? When we use mid = (i+j)/2, the mid is rounded to the lowest integer. In other words, mid is always biased towards the left. This means we could have i == mid when j - i == mid, but we NEVER have j == mid. So in order to keep the search range moving, you must make sure the new i is set to something different than mid, otherwise we are at the risk that i gets stuck. But for the new j, it is okay if we set it to mid, since it was not equal to mid anyways. Our two rules in search of the left boundary happen to satisfy these requirements, so it works perfectly in that situation. Similarly, when we search for the right boundary, we must make sure i won't get stuck when we set the new i to i = mid. The easiest way to achieve this is by making mid biased to the right, i.e. mid = (i+j)/2+1.

All this reasoning boils down to the following simple code:


vector<int> searchRange(int A[], int n, int target) {
    int i = 0, j = n - 1;
    vector<int> ret(2, -1);
    // Search for the left one
    while (i < j)
    {
        int mid = (i + j) /2;
        if (A[mid] < target) i = mid + 1;
        else j = mid;
    }
    if (A[i]!=target) return ret;
    else ret[0] = i;

    // Search for the right one
    j = n-1;  // We don't have to set i to 0 the second time.
    while (i < j)
    {
        int mid = (i + j) /2 + 1;   // Make mid biased to the right
        if (A[mid] > target) j = mid - 1;  
        else i = mid;               // So that this won't make the search range stuck.
    }
    ret[1] = j;
    return ret; 
}


// 3 Search for the position target-0.5 and target+0.5, a simple python code with a little trick
class Solution:
# @param A, a list of integers
# @param target, an integer to be searched
# @return a list of length 2, [index1, index2]
def searchRange(self, arr, target):
    start = self.binary_search(arr, target-0.5)
    if arr[start] != target:
        return [-1, -1]
    arr.append(0)
    end = self.binary_search(arr, target+0.5)-1
    return [start, end]

def binary_search(self, arr, target):
    start, end = 0, len(arr)-1
    while start < end:
        mid = (start+end)//2
        if target < arr[mid]:
            end = mid
        else:
            start = mid+1
    return start

for search the target+0.5 position we add something whatever to the list end to get the right position for the edge case

take ([0,1,2,3,4,5], 5) for example:

we append 0 to the list end

[0,1,2,3,4,5,0]

[4,5,0]# start now is 4, end is 6, mid is 5, start = mid+1 = 6, end the while loop

finally we get the 5.5 position == start == 6

// 4
class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> ans(2);
        ans[0] = lowerBound(A, A + n, target) - A;
        ans[1] = upperBound(A, A + n, target) - A - 1;
        if (ans[0] > ans[1]) {
            ans[0] = ans[1] = -1;
        }
        return ans;
    }

    int *lowerBound(int *a, int *b, int target)
    {
        return binarySearch(a, b, target, [](int a, int b) { return a < b; });
    }

    int *upperBound(int *a, int *b, int target)
    {
        return binarySearch(a, b, target, [](int a, int b) { return a <= b; });
    }

    int *binarySearch(int *a ,int *b, int target, function<bool(int, int) > cmp)
    {
        int l = 0, r = b - a;
        while (l < r) { 
            int mid = l + ((r - l) >> 1);
            if (cmp(a[mid], target)) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return a + l;
    }
};


