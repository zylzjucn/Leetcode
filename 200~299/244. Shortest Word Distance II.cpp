class WordDistance {
public:
    WordDistance(vector<string>& v) {
        for (int i = 0; i < v.size(); i++)
            m[v[i]].push_back(i);
    }
    
    int shortest(string s1, string s2) {
        int i = 0, j = 0, res = INT_MAX;
        vector<int> v1 = m[s1];
        vector<int> v2 = m[s2];
        while (i < v1.size() && j < v2.size()) {
            res = min(res, abs(v1[i] - v2[j]));
            v1[i] < v2[j] ? i++ : j++;
        }
        return res;
    }

private:
    unordered_map<string, vector<int>> m;
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(words);
 * int param_1 = obj->shortest(word1,word2);
 */
