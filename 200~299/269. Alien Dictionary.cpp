class Solution {
public:
    string alienOrder(vector<string>& words) {
        string res;
        unordered_map<char, unordered_set<char>> dependencies;
        unordered_map<char, int> map;
        for (const string& word : words) {
            for (const char& c : word) {
                map[c] = 0;
            }
        }
        for (int i = 0; i < words.size(); i++) {
            string s1 = words[i];
            for (int j = i + 1; j < words.size(); j++) {
                string s2 = words[j];
                int k = 0;
                for (; k < min(s1.length(), s2.length()); k++) {
                    if (s1[k] != s2[k]) {
                        if (dependencies[s2[k]].count(s1[k])) {
                            return res;
                        }
                        if (!dependencies[s1[k]].count(s2[k])) {
                            dependencies[s1[k]].insert(s2[k]);
                            map[s2[k]]++;
                        }
                        break;
                    }
                }
                if (k == min(s1.length(), s2.length()) && s1.length() > s2.length()) {
                    return res;
                }
            }
        }
        queue<char> q;
        auto it = map.begin();
        while (it != map.end()) {
            if (it->second == 0) {
                q.push(it->first);
            }
            it++;
        }
        while (!q.empty()) {
            char c = q.front();
            q.pop();
            for (const auto& c_next : dependencies[c]) {
                map[c_next]--;
                if (map[c_next] == 0) {
                    q.push(c_next);
                }
            }
            res.push_back(c);
        }
        return res.length() == map.size() ? res : "";
    }
};
