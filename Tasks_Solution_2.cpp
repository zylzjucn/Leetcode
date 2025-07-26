// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <limits.h>
#include <queue>

using namespace std;

// 解法2:倒序跳步遍历时间
// N*logN, N是tasks数量

int FindMaxSolution(vector<vector<int>>& tasks) {
    sort(tasks.begin(), tasks.end(), [](const vector<int>& a, const vector<int>& b){
        return a[0] > b[0];
    });
    int res = 0;
    priority_queue<int> pq;
    int i = 0;
    int time = INT_MAX;
    while ((i < tasks.size() || !pq.empty()) && time > 0) {
        // 不push，只更新time
        if (pq.empty()) {
            time = tasks[i][0];
        }
        // push统一在这里做
        while (i < tasks.size() && tasks[i][0] == time) {
            pq.push(tasks[i][1]);
            i++;
        }
        res += pq.top();
        pq.pop();
        time--;
    }
    return res;
}

int main() {

    // deadline, profit
    vector<vector<int>> tasks = {{3, 50}, {1, 60}};

    cout << FindMaxSolution(tasks) << endl;
    return 0;
}
