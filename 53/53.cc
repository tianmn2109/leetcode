int maxSubArray(int A[], int n) {

    int max = A[0];

        int b = A[0];

        for (int i = 1; i < n; i ++) {

            if (b > 0)

                b = A[i] + b;

            else

                b = A[i];

            if (b > max)

                max = b;

        }

        return max;

}
