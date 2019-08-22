class Solution {
public:
    string findContestMatch(int n) {
        string res;
        vector<int> v(n);
        v[0] = 1;
        for (int count = 1; count < n; count *= 2) {
            for (int i = count - 1; i >= 0; i--) {
                v[2 * i + 1] = count * 2 + 1 - v[i];
                v[2 * i] = v[i];
            }
        }
        return build(v, 0, n - 1);
    }
    
private:
    string build(vector<int>& v, int start, int end) {
        if (start == end)
            return to_string(v[start]);
        int mid = (start + end) / 2;
        string s1 = build(v, start, mid);
        string s2 = build(v, mid + 1, end);
        return '(' + s1 + ',' + s2 + ')';
    }
};
