class Solution {
public:
    int numSimilarGroups(vector<string>& A) {
        int res = 0;
        int len = A.size();
        vector<int> leader;
        unordered_set<int> leaderset;
        for (int i = 0; i < len; i++)
            leader.emplace_back(i);
        // vector<vector<int>> m(len, vector<int>(len, 0));
        for (int i = 0; i < len; i++)
            for (int j = 0; j < i; j++)
                if (isSimilar(A[i], A[j])) {
                    int leaderi = findLeader(leader, i);
                    int leaderj = findLeader(leader, j);
                    leader[leaderj] = leaderi;
                }
        for (int i = 0; i < len; i++)
            leader[i] = findLeader(leader, i);
        for (int i = 0; i < len; i++)
            if (!leaderset.count(leader[i])) {
                res++;
                leaderset.insert(leader[i]);
            }
        return res;
    }
    
    int findLeader(vector<int>& leader, int x) {
        int res = x;
        while (leader[res] != res)
            res = leader[res];
        return res;
    }
    
    bool isSimilar(string a, string b) {
        int count = 0; 
        int i = 0;
        while (count <= 2 && i < a.length()) {
            if (a[i] != b[i])
                count++;
            i++;
        }
        return count == 2 || count == 0;
    }
};
