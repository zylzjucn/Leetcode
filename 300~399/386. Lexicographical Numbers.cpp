class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        stack<int> s;
        int i = 1;
        while (1) {
            if (i <= n) {
                res.push_back(i);
                if (res.size() == n)
                    break;
                if (10 * i <= n) {
                    s.push(i);
                    i *= 10;
                }
                else if (i < n && i % 10 != 9)
                    i++;
                else {
                    while (!s.empty() && s.top() % 10 == 9) {
                        s.pop();
                    }
                    if (s.empty())
                        break;
                    i = s.top() + 1;
                    s.pop();
                }
            }
        }
        return res;
    }
};
