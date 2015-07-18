vector<int> productExceptSelf(vector<int>& nums) {
    int N = nums.size();
    vector<int> res(N,1);

    for(int i=0; i<N; i++){
        if (i==0)   res[i] = 1;
        else res[i] = res[i-1]*nums[i-1];
    }

    int r_prod = 1;
    for(int i=N-1; i>=0; i--){
        res[i] *= r_prod;
        r_prod *= nums[i];
    }

    return res;
}
