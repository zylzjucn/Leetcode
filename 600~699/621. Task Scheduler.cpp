class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> m;
        int max_task = 0;
        for (const char& task : tasks) {
            m[task]++;
            max_task = max(max_task, m[task]); // 2
        }
        int count_max = 0;
        for (const auto& p : m) {
            if (p.second == max_task) {
                count_max++; // 2
            }
        }
        return max((max_task - 1) * (n + 1) + count_max, (int)tasks.size());
    }
};
