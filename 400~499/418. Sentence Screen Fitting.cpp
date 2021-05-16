class Solution {
public:
    int wordsTyping(vector<string>& strs, int rows, int cols) {
        vector<int> mem(strs.size(), 0);
        int res = 0;
        int j = 0;
        for (int i = 0; i < rows; i++) {
            int len = 0;
            if (mem[j] != 0) {
                j += mem[j];
                res += j / strs.size();
                j = j % strs.size();
            }
            else {
                int old_j = j;
                while (len + strs[j].length() + 1 <= cols + 1) {
                    len += strs[j].length() + 1;
                    j++;
                    mem[old_j]++;
                    if (j == strs.size()) {
                        j = 0;
                        res++;
                    }
                }
            }
        }
        return res;
    }
};
