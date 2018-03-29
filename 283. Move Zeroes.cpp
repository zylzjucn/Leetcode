class Solution {
public:
    void moveZeroes(vector<int>& n) {
        int i = 0, j = 0;
        for (; i < n.size(); i++)
            if (n[i] != 0)
                n[j++] = n[i];
        for (; j < n.size(); j++)
            n[j] = 0;
    }
};
