class Solution {
public:
    int searchInsert(vector<int>& n, int target) {
        int start = 0, end = n.size() - 1, mid;
        while (start <= end) {
            mid = (start + end) / 2;
            if (target > n[mid])
                start = mid + 1;
            else if (target < n[mid])
                end = mid - 1;
            else
                return mid;
        }
        return start; // cuz now end = start - 1 and start is the right positon
    }
};
