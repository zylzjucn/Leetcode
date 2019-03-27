class Solution {
public:
    int longestMountain(vector<int>& v) {
        int res = 0;
        int start = 0, mid = 0, end = 0;
        while (v.size() > 2) {
            for (; (start < v.size() -1) && v[start] >= v[start + 1]; start++);
            if (start == v.size() - 1)
                break;
            mid = start + 1;
            for (; (mid < v.size() - 1) && v[mid] < v[mid + 1]; mid++);
            if (mid == v.size() - 1)
                break;
            end = mid;
            for (; (end < v.size() - 1) && v[end] > v[end + 1]; end++);
            if (v[end - 1] > v[end])
                res = max(res, end - start + 1);
            start = end;
        }
        return res;
    }
};
