class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quicksort(nums, 0, nums.size() - 1);
        return nums;
    }
    
    void quicksort(vector<int>& n, int left, int right) {
        if (left >= right)
            return;
        int piv = left;
        int i = left;
        int j = right;
        while (i < j) {
            for (; j > i && n[j] >= n[piv]; j--);
            swap(n[piv], n[j]);
            piv = j;
            for (; j > i && n[i] <= n[piv]; i++);
            swap(n[piv], n[i]);
            piv = i;
        }
        quicksort(n, left, i - 1);
        quicksort(n, i + 1, right);
    }
};
