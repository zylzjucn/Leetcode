class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        return build(n, n);
    }
    vector<string> build(int a, int n) {
        vector<string> res;
        if (a == 0) {
            res.push_back("");
            return res;
        }
        if (a == 1) {
            res.push_back("0");
            res.push_back("1");
            res.push_back("8");
            return res;
        }
        vector<string> v = build(a - 2, n);
        for (const auto& s : v) {
            if (a != n)
                res.push_back("0" + s + "0");
            res.push_back("1" + s + "1");
            res.push_back("8" + s + "8");
            res.push_back("6" + s + "9");
            res.push_back("9" + s + "6");
        }
        return res;
    }
};
