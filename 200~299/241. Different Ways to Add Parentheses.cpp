class Solution {
public:
    vector<int> diffWaysToCompute(string s) {
        vector<int> res;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '+' || s[i] == '-' || s[i] == '*') {
                vector<int> v1 = diffWaysToCompute(s.substr(0, i));
                vector<int> v2 = diffWaysToCompute(s.substr(i + 1));
                for (const auto& a : v1)
                    for (const auto& b : v2) {
                        if (s[i] == '+')
                            res.push_back(a + b);
                        else if (s[i] == '-')
                            res.push_back(a - b);
                        else
                            res.push_back(a * b);
                    }
            }
        }
        if (res.size() == 0)
            res.push_back(stoi(s));
        return res;
    }
};
