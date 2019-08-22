class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;
        queue<int> q;
        vector<int> lock(numCourses, 0);
        vector<int> v1;
        vector<vector<int>> v(numCourses, v1);
        for (const auto& vpair : prerequisites) {
            lock[vpair[0]]++;
            v[vpair[1]].push_back(vpair[0]);
        }
        for (int i = 0; i < numCourses; i++)
            if (lock[i] == 0)
                q.push(i);
        while (!q.empty()) {
            int cur = q.front();
            res.push_back(cur);
            q.pop();
            for (const auto& i : v[cur]) {
                lock[i]--;
                if (lock[i] == 0)
                    q.push(i);
            }
        }
        if (res.size() != numCourses)
            res.clear();
        return res;
    }
};
