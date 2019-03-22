class Solution {
public:
    int findKthLargest(vector<int>& n, int k) {
        sort(n.begin(), n.end());
        int i = n.size() - k;
        return n[i];
    }
};
