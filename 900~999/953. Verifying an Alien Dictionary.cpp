class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> dict(256, 0);
        for (int i = 0; i < order.length(); i++)
            dict[order[i]] = i;
        for (int i = 0; i < words.size() - 1; i++) {
            if (!cmp(words[i], words[i + 1], dict))
                return false;
        }
        return true;
    }
    
    bool cmp(const string& s1, const string& s2, const vector<int>& dict) {
        int i = 0;
        for (; i < min(s1.length(), s2.length()); i++) {
            if (dict[s1[i]] < dict[s2[i]])
                return true;
            else if (dict[s1[i]] > dict[s2[i]])
                return false;
        }
        return s1.length() <= s2.length();
    }
};
