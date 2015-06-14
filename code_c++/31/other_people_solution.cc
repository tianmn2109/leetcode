 void nextPermutation(vector<int> &num) {
        int len = num.size();
        int i,j;
        for(i = len - 2; i >= 0 ; i--)
            if(num[i] < num[i+1]) break;

        for(j = len - 1; j > i; j--)
            if(num[j] > num[i]) break;

        swap(num[i],num[j]);
        reverse(num.begin()+i+1,num.end());
        return;
    }
