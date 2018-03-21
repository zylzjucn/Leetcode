class Solution {
public:
    int myAtoi(string s) {
        int i = 0, sum = 0, flag = 1;
        while (s[i] == ' ')
            i++;
        if (s[i] == '+' || s[i] == '-') {
            flag = (s[i] == '+') ? 1 : -1;
            i++;
        }
        while (s[i] >= '0' && s[i] <= '9') {
            if ((sum > INT_MAX / 10 || (sum == INT_MAX / 10 && s[i] >= '7')) && flag == 1)
                return INT_MAX;
            if ((sum > INT_MAX / 10 || (sum == INT_MAX / 10 && s[i] >= '8')) && flag == -1)
                return INT_MIN;
            sum = 10 * sum +  s[i++] - '0';
        }
        return flag * sum;
    }
};
