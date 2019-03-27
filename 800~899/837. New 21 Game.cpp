class Solution {
public:
    double new21Game(int N, int K, int W) {
        queue<double> q;
        double res = 1.0;
        double sum = 0;
        for (int i = 0; i < W; ++i) {
            if (i < W - (N - K + 1))
                q.push(0);
            else {
                sum++;
                q.push(1);
            }
        }
        for (int i = K - 1; i >= 0; --i) {
            res = sum / W;
            sum += res - q.front();
            q.pop();
            q.push(res);
        }
        return res;
    }
};
