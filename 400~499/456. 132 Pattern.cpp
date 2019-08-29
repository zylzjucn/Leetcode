class Solution {
public:
    bool find132pattern(vector<int>& n) {
        stack<int> s;
        int n3 = INT_MIN;
        for (int i = n.size() - 1; i >= 0; i--) {
            if (n[i] < n3)
                return true;
            else {
                while (!s.empty() && n[i] > s.top()) {
                    n3 = s.top();
                    s.pop();
                }
            }
            s.push(n[i]);
        }
        return false;
    }
};
