class Solution {
public:
    vector<int> asteroidCollision(vector<int>& v) {
        vector<int> res;
        if (v.size() == 0)
            return res;
        stack<int> s;
        int right = 0;
        int i = 0;
        while (i < v.size() || right != 0) {
            if (right == 0)
                right = v[i++];
            if (s.empty()) {
                s.push(right);
                right = 0;
                continue;
            }
            int left = s.top();
            if (left * right > 0 || left < 0) {
                s.push(right);
                right = 0;
            }
            else if (left + right == 0) {
                right = 0;
                s.pop();
            }
            else if (left + right < 0) {
                s.pop();
            }
            else {
                right = 0;
            }   
        }
        while (!s.empty()) {
            res.push_back(s.top());
            s.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
