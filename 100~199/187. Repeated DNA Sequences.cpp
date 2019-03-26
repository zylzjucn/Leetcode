class Solution {
public:
    vector<string> findRepeatedDnaSequences(string str) {
        vector<string> result;
        if (str.length() < 10)
            return result;
        unordered_set<string> s;
        unordered_set<string> res;
        for (int i = 0; i <= str.length() - 10; i++) {
            string t = str.substr(i, 10);
            if (s.find(t) != s.end())
                res.insert(t);
            else
                s.insert(t);
        }
        for (auto it = res.begin(); it != res.end(); it++)
            result.push_back(*it);
        return result;
    }
};
