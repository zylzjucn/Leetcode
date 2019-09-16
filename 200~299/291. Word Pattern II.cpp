class Solution {
public:
    bool wordPatternMatch(string pattern, string str) {
        // unordered_map<char, string> dict;
        vector<string> v(26, "");
        unordered_set<string> words;
        return match(pattern, 0, str, 0, v, words);
    }
    
    bool match(string& p, int i, string& s, int j, vector<string>& dict, unordered_set<string>& words) {
        if (i == p.size() || j == s.size())
            return i == p.size() && j == s.size();
        if (dict[p[i] - 'a'] != "") {
            string word = dict[p[i] - 'a'];
            if (s.substr(j, word.length()) != word)
                return false;
            return match(p, i + 1, s, j + word.length(), dict, words);
        }
        else {
            for (int k = j; k < s.length(); k++) {
                string word = s.substr(j, k - j + 1);
                if (words.count(word))
                    continue;
                words.insert(word);
                dict[p[i] - 'a'] = word;
                if (match(p, i + 1, s, k + 1, dict, words))
                    return true;
                words.erase(word);
                dict[p[i] - 'a'] = "";
            }
        }
        return false;
    }
};
