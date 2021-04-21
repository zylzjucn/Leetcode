class Solution {
public:
    string removeDuplicates(string str, int k) {
        string res;
        stack<pair<char, int>> s;
        for (const auto& c : str) {                
            if (!s.empty() && s.top().first == c)
                s.top().second++;
            else
                s.emplace(c, 1);
            if (s.top().second == k)
                s.pop();
        }
        for (; !s.empty(); s.pop())
            res.append(s.top().second, s.top().first);
        reverse(res.begin(), res.end());
        return res;
    }
};
