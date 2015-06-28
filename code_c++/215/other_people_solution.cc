First version, using std::sort, and return the k-th (from the end) entry

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());
        return nums[nums.size()-k];
}
};
Second version, using a heap, and pop up k-1 entries, the left top one is what we need

int findKthLargest(vector<int>& nums, int k) {
    make_heap(nums.begin(), nums.end());
    for(auto i=0; i<k-1;i++)
    {
        pop_heap(nums.begin(), nums.end());
        nums.pop_back();
    }
    return nums.front();
Third one, do quicksort, use the first entry as pivot and divide the array in two parts, the first half is the one no less than pivot and the second half is the one less then pivot. Then based on the length of the first half, decide to proceed in which half.

int findKthLargest(vector<int>& nums, int k) {
    int i, m,n, pivot, head =0, tail=nums.size()-1, maxV;

    while(1)
    {
        m = head, n= tail;
        pivot = nums[m++];
        while(m<=n)
        {
            if(nums[m]>=pivot) m++;
            else if(nums[n]<pivot) n--;
            else {swap(nums[m++], nums[n--]);}
        }
        if(m-head == k) return pivot;
        else if(m-head < k) {k -= (m-head); head = m;  }
        else {tail = m-1;head = head+1;}
    }

}
};


Solution 1: O(nlgk) by using min-heap

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        size_t len = nums.size();
        if(len < k) return 0;

        priority_queue<int, std::vector<int>, std::greater<int>> q;
        for(auto &v : nums)
        {
            if(q.size() < k)
            {
                q.push(v);
            }
            else if (v > q.top())
            {
                q.pop();
                q.push(v);
            }
        }
        return q.top();
    }
};
Solution 2: O(n) by partitioning recursively

class Solution {
public:
    int partition(vector<int>& nums, int i, int j)
    {
        if (i == j) return i;

        int pivot = nums[i];
        std::swap(nums[i], nums[j]);

        int i0 = i;
        for(int k = i; k < j; k ++)
        {
            if(nums[k] <= pivot)
            {
                std::swap(nums[k], nums[i0 ++]);
            }
        }
        std::swap(nums[i0], nums[j]);
        return i0;
    }
    int findKthLargest(vector<int>& nums, int k) 
    {
        size_t len = nums.size();
        int pi = 0;
        int tgt = len - k;

        int a = 0, b = len - 1;
        while((pi = partition(nums, a, b)) != tgt)
        {
            if(pi < tgt)
            {
                a = pi + 1;
            }
            else if(pi > tgt)
            {
                b = pi - 1;
            }
        }
        return nums[pi];
    }
};
