class Solution {
public:
    void wiggleSort(vector<int>& n) {
        for (int i = 0; i < n.size(); i++)
            if ((i % 2 && n[i] < n[i - 1]) || (i % 2 == 0 && i != 0 && n[i] > n[i - 1]))
                swap(n[i], n[i - 1]);
    }
}
