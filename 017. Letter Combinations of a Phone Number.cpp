class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> v;
        if (digits.length() == 0)
            return v;
        string charmap[10] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        v.push_back("");
        for (int i = 0; i < digits.size(); i++) {
            vector<string> temp;
            string s = charmap[digits[i] - '0'];
            for (int j = 0; j < s.size(); j++)
                for (int k = 0; k < v.size(); k++)
                    temp.push_back(v[k] + s[j]);
            v = temp;
        }
        return v;
    }
};
