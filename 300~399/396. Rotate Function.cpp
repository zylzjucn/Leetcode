class Solution {
public:
    int maxRotateFunction(vector<int>& n) {
        long long sum = 0;
        long long sum0 = 0;
        for (int i = 0; i < n.size(); i++) {
            sum += n[i];
            sum0 += i * n[i];
        }
        long long res = sum0;
        for (int i = 1; i < n.size(); i++) {
            sum0 += sum - n.size() * n[n.size() - i];
            res = max(res, sum0);
        }
        return res;
    }    
};
