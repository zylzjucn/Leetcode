class Solution {
public:
    int shortestWay(string t, string s) {
        int res = 0;
        int i = 0;
        int pre = 0;
        while (i < s.length()) {
            int j = 0;
            while (j < t.length() && i < s.length()) {
                if (s[i] == t[j])
                    i++;
                j++;
            }
            res++;
            if (i == pre)
                return -1;
            pre = i;
        }
        return res;
    }
};
