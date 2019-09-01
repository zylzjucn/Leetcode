class Solution {
public:
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
        unordered_map<string, string> leader;
        for (const auto& p : pairs) {
            if (!leader.count(p[0]))
                leader[p[0]] = p[0];
            if (!leader.count(p[1]))
                leader[p[1]] = p[1];
            string s0 = findLeader(leader, p[0]);
            string s1 = findLeader(leader, p[1]);
            leader[s1] = s0;
        }
        if (words1.size() != words2.size())
            return false;
        for (int i = 0; i < words1.size(); i++) {
            if (words1[i] == words2[i] || findLeader(leader, words1[i]) == findLeader(leader, words2[i]))
                continue;
            return false;
        }
        return true;
    }
    
    string findLeader(unordered_map<string, string>& leader, string s) {
        while (leader[s] != s) {
            leader[s] = leader[leader[s]];
            s = leader[s];
        }
        return s;
    }
};
