class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> res;
        if (s.length() == 0)
            return res;
        for (int i = 0; i < s.length() - 1; i++)
            if (s.substr(i, 2) == "++") {
                res.push_back(s);
                res.back()[i] = '-';
                res.back()[i + 1] = '-';
            }
        return res;
    }
};
