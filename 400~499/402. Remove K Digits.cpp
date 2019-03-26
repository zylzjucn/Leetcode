class Solution {
public:
    string removeKdigits(string num, int k) {
        string res;
        for (const auto& c : num) {
            while (res.length() && res.back() > c && k) {
                res.pop_back();
                k--;
            }
            if (res.length() || c > '0')
                res.append(1, c);
        }
        res = res.substr(0, res.length() - k);
        return res.empty() ? "0" : res;
    }
};
