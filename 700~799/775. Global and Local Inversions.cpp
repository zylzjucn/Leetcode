class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        int tmp = INT_MIN;
        for (int i = 1; i < A.size(); i++) {
            if (A[i] < tmp)
                return false;
            tmp = max(tmp, A[i - 1]);
        }
        return true;
    }
};
