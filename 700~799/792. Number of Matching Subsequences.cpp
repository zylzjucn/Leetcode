class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int res = 0;
        unordered_map<string, int> m;
        for (const auto& word : words)
            m[word]++;
        for (const auto& p : m) {
            string word = p.first;
            int count = p.second;
            int i = 0;
            int j = 0;
            while (i < s.length()) {
                if (s[i] == word[j]) {
                    j++;
                    if (j == word.length()) {
                        res += count;
                        break;
                    }
                }
                i++;
            }
        }
        return res;
    }
};
