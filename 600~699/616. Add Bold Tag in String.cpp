class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) {
        if (s.length() == 0 || dict.size() == 0)
            return s;
        vector<bool> bold(s.length(), false);
        for (int i = 0; i < s.length(); i++)
            for (const auto& word : dict)
                if (i + word.length() <= s.length() && s.substr(i, word.length()) == word)
                    for (int j = 0; j < word.length(); j++)
                        bold[i + j] = true;
        string res;
        for (int i = 0; i < s.length(); i++) {
            if (bold[i] && (i == 0 || !bold[i - 1]))
                res.append("<b>");
            else if (!bold[i] && i > 0 && bold[i - 1])
                res.append("</b>");
            res.append(1, s[i]);
        }
        if (bold.back())
            res.append("</b>");
        return res;
    }
}
