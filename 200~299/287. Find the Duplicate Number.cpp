class Solution {
public:
    int findDuplicate(vector<int>& n) {
        if (n.size() < 2)
            return -1;
        int i = n[0];
        int j = n[n[0]];
        while (i != j) {
            i = n[i];
            j = n[n[j]];
        }
        i = 0;
        while (i != j) {
            i = n[i];
            j = n[j];
        }
        return i;
    }
};
