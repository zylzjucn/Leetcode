class Solution {
public:
    bool verifyPreorder(vector<int>& v) {
        stack<int> s;
        int maxleft = INT_MIN;
        for (const auto& x : v) {
            if (maxleft >= x)
                return false;
            while (!s.empty() && s.top() < x) {
                maxleft = max(maxleft, s.top());
                s.pop();
            }
            s.push(x);
        }
        return true;
    }
};
