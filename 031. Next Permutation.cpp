class Solution {
public:
    void nextPermutation(vector<int>& n) {
        int i = n.size() - 2;
        for (; i >= 0 && n[i] >= n[i + 1]; i--);
        int j = i + 1;
        if (i != -1) {
            for (; n[j] > n[i] && j < n.size(); j++);
            j--;
            swap(n[i], n[j]);
        }
        j = n.size() - 1;
        i++;
        for (; i < j; swap(n[i++], n[j--]));
    }
};
