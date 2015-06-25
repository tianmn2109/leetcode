int candy(vector<int> &ratings) {
    // Note: The Solution object is instantiated only once and is reused by each test case.
    int nCandyCnt = 0;///Total candies
    int nSeqLen = 0;  /// Continuous ratings descending sequence length
    int nPreCanCnt = 1; /// Previous child's candy count
    int nMaxCntInSeq = nPreCanCnt;
    if(ratings.begin() != ratings.end())
    {
        nCandyCnt++;//Counting the first child's candy.
        for(vector<int>::iterator i = ratings.begin()+1; i!= ratings.end(); i++)
        {
            // if r[k]>r[k+1]>r[k+2]...>r[k+n],r[k+n]<=r[k+n+1],
            // r[i] needs n-(i-k)+(Pre's) candies(k<i<k+n)
            // But if possible, we can allocate one candy to the child,
            // and with the sequence extends, add the child's candy by one
            // until the child's candy reaches that of the prev's.
            // Then increase the pre's candy as well.

            // if r[k] < r[k+1], r[k+1] needs one more candy than r[k]
            // 
            if(*i < *(i-1))
            {
                //Now we are in a sequence
                nSeqLen++;
                if(nMaxCntInSeq == nSeqLen)
                {
                    //The first child in the sequence has the same candy as the prev
                    //The prev should be included in the sequence.
                    nSeqLen++;
                }
                nCandyCnt+= nSeqLen;
                nPreCanCnt = 1;
            }
            else
            {
                if(*i > *(i-1))
                { 
                    nPreCanCnt++;
                }
                else
                {
                    nPreCanCnt = 1;
                }
                nCandyCnt += nPreCanCnt;
                nSeqLen = 0;
                nMaxCntInSeq = nPreCanCnt;
            }   
        }
    }
    return nCandyCnt;
}
