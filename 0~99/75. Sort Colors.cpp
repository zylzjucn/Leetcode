class Solution {
public:
    void sortColors(vector<int>& n) {
        int left = 0;
        int i = 0;
        int right = n.size() - 1;
        while (i <= right) {
            if (n[i] == 0)
                swap(n[i++], n[left++]);
            else if (n[i] == 2)
                swap(n[i], n[right--]);
            else
                i++;
        }
    }
};
