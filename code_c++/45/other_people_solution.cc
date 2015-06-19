// 1
int jump(int A[], int n) {
    if(n == 0){
        return 0;
    }
    int maxReachPos = A[0];
    int curMaxReachPos = A[0];
    int curStep = 1;
    for(int i = 1; i <= min(n, maxReachPos); i++){
        curMaxReachPos = max(curMaxReachPos, i + A[i]);
        if(i == n - 1){
            return curStep;
        }
        if(i == maxReachPos){
            maxReachPos = curMaxReachPos;
            curStep++;
        }
    }
    return 0;
}

The variable maxReachPos indicates the farthest reachable position and the variable curMaxReachPos indicates the current farthest reachable position.

At the very beginning, both maxReachPos and curMaxReachPos are equal to A[0].

In the For loop, we keep updating curMaxReachPos while i <= maxReachPos. However, if( i == n - 1), we return curStep, which is the minimum step. If i reaches the maxReachPos, we update maxReachPos with curMaxReachPos and increment curStep by one. 
