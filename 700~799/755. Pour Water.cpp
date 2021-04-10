class Solution {
public:
    vector<int> pourWater(vector<int>& v, int V, int K) {
        for (int drop = 0; drop < V; drop++) {
            int i = K;
            while (i > 0 && v[i - 1] <= v[i])
                i--;
            while (i < K && v[i + 1] == v[i])
                i++;
            while (i < v.size() - 1 && v[i + 1] <= v[i])
                i++;
            while (i > K && v[i - 1] == v[i])
                i--;
            v[i]++;
        }
        return v;
    }
};
