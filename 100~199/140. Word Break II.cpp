class Solution {
public:
    vector<string> wordBreak(string str, vector<string>& wordDict) {
        unordered_set<string> s;
        for (const auto& word : wordDict)
            s.insert(word);
        vector<string> res;
        vector<vector<string>> paths(str.length() + 1);
        paths[0].push_back("");
        for (int i = 0; i < str.length(); i++) {
            if (paths[i].size() == 0)
                continue;
            else {
                for (int j = 1; i + j <= str.length(); j++) {
                    string tmp = str.substr(i, j);
                    if (s.count(tmp)) {
                        for (auto path : paths[i]) {
                            if (path == "")
                                paths[i + j].push_back(tmp);
                            else
                                paths[i + j].push_back(path + " " + tmp);
                        }
                    }
                }
            }
        }
        return paths.back();
    }
};
