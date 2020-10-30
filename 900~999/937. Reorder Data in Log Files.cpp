class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> res;
        vector<pair<string, string>> log_letter;
        vector<int> index;
        vector<string> log_digit;
        for (const string& s : logs) {
            if (isalpha(s.back())) {
                int i = 0;
                for (; s[i] != ' '; i++);
                log_letter.emplace_back(s.substr(0, i), s.substr(i + 1));
            }
            else
                log_digit.push_back(s);
        }
        sort(log_letter.begin(), log_letter.end(), [](pair<string, string> a, pair<string, string> b) {
            return a.second < b.second || (a.second == b.second && a.first < b.first);
        });
        for (const auto& p : log_letter)
            res.push_back(p.first + " " + p.second);
        for (const string& s : log_digit)
            res.push_back(s);
        return res;
    }
};
