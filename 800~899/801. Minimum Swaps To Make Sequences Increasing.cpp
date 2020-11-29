class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        int swap = 1;
        int not_swap = 0;
        for (int i = 1; i < A.size(); i++) {
            int swap_new = INT_MAX;
            int not_swap_new = INT_MAX;
            if (A[i - 1] < A[i] && B[i - 1] < B[i]) {
                swap_new = min(swap_new, swap + 1);
                not_swap_new = min(not_swap_new, not_swap);
            }
            if (A[i - 1] < B[i] && B[i - 1] < A[i]) {
                swap_new = min(swap_new, not_swap + 1);
                not_swap_new = min(not_swap_new, swap);
            }
            swap = swap_new;
            not_swap = not_swap_new;
        }
        return min(swap, not_swap);
    }
};
