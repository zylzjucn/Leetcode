class Solution {
public:
    bool search(vector<int>& n, int t) {
        int left = 0;
        int right = n.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (n[mid] == t)
                return true;
            if (n[left] == n[mid] && n[mid] == n[right]) {
                left++;
                right--;
            }
            else if (n[left] <= n[mid]) {
                if (n[left] <= t && t < n[mid])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            else {
                if (n[mid] < t && t <= n[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }
        return false;
    }
};
