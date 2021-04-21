class Solution {
public:
    string alienOrder(vector<string>& words) {
        string res;
        queue<char> q;
        unordered_map<char, int> dependencies;
        unordered_map<char, unordered_set<char>> m;
        unordered_set<char> met;
        unordered_set<char> s;
        unordered_set<char> total;
        for (const auto& str : words) {
            for (const auto& c : str) {
                total.insert(c);
                s.insert(c);
            }
        }
        for (int i = 0; i < words.size() - 1; i++) {
            int j = 0;
            for (; j < min(words[i].length(), words[i + 1].length()); j++) {
                if (words[i][j] != words[i + 1][j])
                    break;
            }
                
            if (j == words[i].length())
                continue;
            if (!m[words[i][j]].count(words[i + 1][j])) {
                dependencies[words[i + 1][j]]++;
                s.erase(words[i + 1][j]);
                m[words[i][j]].insert(words[i + 1][j]);
            }
        }
        for (const auto& it : s) {
            q.push(it);
            met.insert(it);
        }
        while (!q.empty()) {
            char c = q.front();
            q.pop();
            res.push_back(c);
            for (const auto& c1 : m[c]) {
                if (dependencies[c1] > 0) {
                    dependencies[c1]--;
                    if (dependencies[c1] == 0 && !met.count(c1)) {
                        q.push(c1);
                        met.insert(c1);
                    }
                }
            }
        }
        return res.length() == total.size() ? res : "";
    }
};
