class Solution {
public:
    int numTrees(int n) {
        int a[n+1] = {0}, i, j;
        a[0] = 1;
        a[1] = 1;
        for (i = 2; i <= n; i++)
            for(j = 0; j < i; j++)
                a[i] += a[j] * a[i - 1 - j];
        return a[n];
    }
};
