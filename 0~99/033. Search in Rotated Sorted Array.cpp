class Solution {
public:
    int search(vector<int>& n, int target) {
        if (n.size() == 0)
            return -1;
        int start = 0, end = n.size() - 1;
        if (n[start] < n[end])
            return searchSorted(n, start, end, target);
        while (start < end && n[start] > n[end]) {
            int mid = (start + end) / 2;
            if (n[mid] >= n[start])
                start = mid + 1;
            else
                end = mid;
        }
        int res1 = searchSorted(n, 0, start - 1, target);
        int res2 = searchSorted(n, start, n.size() - 1, target);
        return res1 != -1 ? res1 : res2 == -1 ? -1 : res2;
    }
    int searchSorted(vector<int> n, int left, int right, int target) {
        int start = left, end = right;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (target > n[mid])
                start = mid + 1;
            else if (target < n[mid])
                end = mid - 1;
            else
                return mid;
        }
        return -1;
    }
};
