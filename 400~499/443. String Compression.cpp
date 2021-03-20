class Solution {
public:
    int compress(vector<char>& chars) {
        int res = 0;
        int start = 0;
        int pos = 0;
        while (start < chars.size()) {
            int end = start;
            while (end < chars.size() && chars[end] == chars[start])
                end++;
            res += log10(end - start) + 2;
            chars[pos++] = chars[start];
            if (end - start == 1)
                res--;
            else {
                string s = to_string(end - start);
                for (int i = 0; i < s.length(); i++) {
                    chars[pos] = s[i];
                    pos++;
                }
            }
            start = end;
        }
        return res;
    }
};
