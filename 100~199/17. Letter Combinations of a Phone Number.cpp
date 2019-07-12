class Solution {
public:
    vector<string> letterCombinations(string d) {
        vector<string> v = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res;
        if (d.length() == 0)
            return res;
        res.push_back("");
        for (const auto& c : d) {
            int tmp = c - '2';
            int len = res.size();
            for (int i = 0; i < len; i++)
                for (const auto& l : v[tmp])
                    res.push_back(res[i] + l);
            res.erase(res.begin(), res.begin() + len);
        }
        return res;
    }
};
