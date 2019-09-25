class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int len = A.size();
        for (int i = 0, a = 0, b = 0; A[i] == A[0] || B[i] == A[0]; i++) {
            if (A[i] != A[0])
                a++;
            if (B[i] != A[0])
                b++;
            if (i == len - 1)
                return min(a, b);
        }
        for (int i = 0, a = 0, b = 0; A[i] == B[0] || B[i] == B[0]; i++) {
            if (A[i] != B[0])
                a++;
            if (B[i] != B[0])
                b++;
            if (i == len - 1)
                return min(a, b);
        }
        return -1;
    }
};
