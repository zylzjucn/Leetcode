class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> dict;
        for (const string& word : words) {
            dict[word]++;
        }
        int len = words[0].length();
        int length = words[0].length() * words.size();
        vector<int> res;
        for (int i = 0; i < len; i++) {
            unordered_map<string, int> seen;
            int start = i; // 0
            int end = start; // 0
            while (end + len <= s.length()) {
                string str = s.substr(end, len);
                end += len;
                if (!dict.count(str)) {
                    start = end;
                    seen.clear();
                } else {
                    seen[str]++;
                    while (seen[str] > dict[str]) {
                        seen[s.substr(start, len)]--;
                        start += len;
                    }
                    if (end - start == length) {
                        res.push_back(start);
                    }
                }
            }
        }
        return res;
    }
};
