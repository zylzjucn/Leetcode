class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int i = 0, j = 0;
        while (i < word.length() && j < abbr.length()) {
            if (isalpha(abbr[j])) {
                if (word[i] == abbr[j]) {
                    i++;
                    j++;
                } else {
                    return false;
                }
            } else {
                int k = j;
                for (; k < abbr.length() && isdigit(abbr[k]); k++);
                if (abbr[j] == '0') {
                    return false;
                }
                int len = stoi(abbr.substr(j, k - j));
                j = k;
                if (i + len <= word.length()) {
                    i += len;
                } else {
                    return false;
                }
            }
        }
        return i == word.length() && j == abbr.length();
    }
};
