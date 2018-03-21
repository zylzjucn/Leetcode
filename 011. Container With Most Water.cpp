class Solution {
public:
    int maxArea(vector<int>& h) {
        int i = 0;
        int j = h.size() - 1;
        int water = min(h[i], h[j]) * (j - i);
        while (i < j) {
            if (h[i] < h[j])
                i++;
            else
                j--;
            water = max(water, min(h[i], h[j]) * (j - i));
        }
        return water;
    }
};
