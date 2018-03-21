class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> m = {{'I', 1}, {'X', 10}, {'C', 100}, {'M', 1000}, {'V', 5}, {'L', 50}, {'D', 500}};
        int i = s.length()-1;
        int sum = m[s[i]];
        for (; i != 0; i--) {
            if (m[s[i - 1]] < m[s[i]])
                sum -= m[s[i - 1]];
            else
                sum += m[s[i - 1]];
        }
        return sum;
    }
};
