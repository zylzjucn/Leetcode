class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<int> locked(n, 0);
        vector<vector<int>> locking(n, vector<int>());
        unordered_set<int> noPreCourses;
        for (int i = 0; i < n; i++)
            noPreCourses.insert(i);
        for (const auto& v : prerequisites) {
            noPreCourses.erase(v[0]);
            locked[v[0]]++;
            locking[v[1]].push_back(v[0]);
        }
        queue<int> q;
        for (const auto& k : noPreCourses)
            q.push(k);
        int countTaken = 0;
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            countTaken++;
            for (const auto& courseUnlock : locking[course]) {
                locked[courseUnlock]--;
                if (locked[courseUnlock] == 0)
                    q.push(courseUnlock);
            }
        }
        return countTaken == n;
    }
};
