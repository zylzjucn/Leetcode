class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> set;
        for (const string& gene : bank) {
            set.insert(gene);
        }
        int step = 0;
        queue<string> q;
        q.push(startGene);
        q.push("");
        while (q.size() > 1) {
            string gene = q.front();
            if (gene == endGene) {
                return step;
            }
            q.pop();
            if (gene == "") {
                q.push("");
                step++;
            } else {
                auto it = set.begin();
                while (it != set.end()) {
                    if (isAdjacent(*it, gene)) {
                        q.push(*it);
                        it = set.erase(it);
                    } else {
                        it++;
                    }
                }
            }
        }
        return -1;
    }

    bool isAdjacent(const string& a, const string& b) {
        if (a.length() != b.length()) {
            return false;
        }
        int i = 0;
        for (; i < a.length() && a[i] == b[i]; i++);
        return i < a.length() && a.substr(i + 1) == b.substr(i + 1); 
    }
};
