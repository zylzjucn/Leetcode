class Solution {
public:
    bool isScramble(string s1, string s2) {
        int len = s1.length();
        vector<vector<vector<bool>>> dp(len + 1, vector<vector<bool>>(len, vector<bool>(len, false)));
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                dp[1][i][j] = s1.substr(i, 1) == s2.substr(j, 1);
            }
        }
        for (int length = 2; length <= len; length++) {
            for (int i = 0; i < len - length + 1; i++) {
                for (int j = 0; j < len - length + 1; j++) {
                    for (int sub_len = 1; sub_len < length; sub_len++) {
                        if (dp[sub_len][i][j] && dp[length - sub_len][i + sub_len][j + sub_len]) {
                            dp[length][i][j] = true;
                        }
                        if (dp[sub_len][i][j + length - sub_len] && dp[length - sub_len][i + sub_len][j]) {
                            dp[length][i][j] = true;
                        }
                    }
                }
            }
        }
        return dp[len][0][0];
    }
};
