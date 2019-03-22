class Solution {
public:
    void rotate(vector<int>& n, int k) {
        n.size() != 0 ? k = n.size() - k % n.size() : 1;
        int i = 0;
        for(; i < k; i++)
            n.push_back(n[i]);
        n.erase(n.begin(), n.begin() + k);
    }
};
