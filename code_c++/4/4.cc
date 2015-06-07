/* 参考网上的答案的
 * 算法思想
 * 找第k小的数
 * 分别对两个数组找 第 k/2 小的数 进行比较
 *
 *
 */
class Solution {
public:
    double findKthMin(int A[],int m,int B[],int n,int k) {
        if (m > n)                                  //A中的个数 始终小于 B 中的元素个数
            return findKthMin(B,n,A,m,k);
        if (m == 0)
           return B[k -1];                          //如果 A为空 则直接返回B中的第k小的数值
        if (k == 1)                                 //如果是第一小的数 只需比较两个数组的第一个元素
            return A[0] < B[0] ? A[0] : B[0];     
        
        int posA = min(k/2,m);                      //确定A数组中要找的第X小的数，防止其小于k/2
        int posB = k - posA;
        if (A[posA - 1] == B[posB - 1])            //两个k/2相等 则返回任意一个
            return A[posA - 1];
        if (A[posA - 1] < B[posB - 1])             //否则分两种情况返回
            return findKthMin(A + posA,m - posA,B,n,k - posA);
        else if (A[posA - 1] > B[posB - 1])
            return findKthMin(A,m,B + posB,n - posB,k - posB);
    }
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if ((m + n) % 2)
            return findKthMin(A,m,B,n,(m + n) / 2 + 1);
        else
            return ( findKthMin(A,m,B,n,(m + n) / 2) +
                     findKthMin(A,m,B,n,(m + n) / 2 + 1) ) / 2;
    }
};
