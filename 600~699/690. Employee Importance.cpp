/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, int> importances;
        unordered_map<int, vector<int>> subs;
        for (const auto& employee : employees) {
            importances[employee->id] = employee->importance;
            subs[employee->id] = employee->subordinates;
        }
        int res = 0;
        queue<int> q;
        q.push(id);
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            res += importances[cur];
            for (const auto& next : subs[cur])
                q.push(next);
        }
        return res;
    }
};
