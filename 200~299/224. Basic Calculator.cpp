class Solution {
public:
    int calculate(string s) {
        int res = 0;
        int a = 0;
        int op = 1;
        int flag = 1;
        stack<int> st;
        for (int i = 0; i < s.length(); i++) {
            a = 0;
            if (s[i] == ' ')
                continue;
            else if (s[i] == '+')
                op = 1;
            else if (s[i] == '-')
                op = -1;
            else if (s[i] == '(') {
                if (i > 0 && s[i - 1] == '-') {
                    flag = -flag;
                    op = -op;
                    st.push(-1);
                }
                else
                    st.push(1);
            }
            else if (s[i] == ')') {
                if (st.top() == -1)
                    flag = -flag;
                st.pop();
            }
            else {
                for (; s[i] <= '9' && s[i] >= '0' && i < s.length(); i++)
                    a = 10 * a + s[i] - '0';
                i--;
            }
            res += op * flag * a;
        }
        return res;
    }
};
