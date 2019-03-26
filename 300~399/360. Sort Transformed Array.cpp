class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& n, int a, int b, int c) {
        vector<int> res(n.size(), 0);
        int left = 0;
        int right = n.size() - 1;
        int i = a >= 0 ? right : left;
        while (left <= right) {
            if (a >= 0)
                res[i--] = qua(n[left], a, b, c) > qua(n[right], a, b, c) ? qua(n[left++], a, b, c) : qua(n[right--], a, b, c);
            else
                res[i++] = qua(n[left], a, b, c) < qua(n[right], a, b, c) ? qua(n[left++], a, b, c) : qua(n[right--], a, b, c);
        }
        return res;
    }
    int qua(int x, int a, int b, int c) {
        return a * x * x + b * x + c;
    }
};
