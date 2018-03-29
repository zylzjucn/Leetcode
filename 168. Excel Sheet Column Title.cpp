class Solution {
public:
    string convertToTitle(int n) {
        string s;
        stack<int> st;
        int p;
        while (n) {
            st.push(n % 26 == 0 ? 26 : n % 26 );
            --n /= 26;
        }
        while (!st.empty()) {
            s.push_back(st.top() + 64);
            st.pop();
        }
        return s;
    }
};
