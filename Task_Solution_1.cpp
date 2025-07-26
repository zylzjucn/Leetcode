#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <limits.h>
#include <queue>

using namespace std;

// 解法1:倒序遍历时间
// N*logN + D*logN
// 如果tasks在时间上比较稀疏，则效率低

int FindMaxSolution(vector<vector<int>>& tasks) {
    sort(tasks.begin(), tasks.end(), [](const vector<int>& a, const vector<int>& b){
        return a[0] > b[0];
    });
    int res = 0;
    priority_queue<int> pq;
    int i = 0;
    for (int time = tasks[0][0]; time > 0; time--) {
        while (i < tasks.size() && tasks[i][0] == time) {
            pq.push(tasks[i][1]);
            i++;
        }
        if (!pq.empty()) {
            res += pq.top();
            pq.pop();
        }
    }
    return res;
}

int main() {

    // deadline, profit
    vector<vector<int>> tasks = {{3, 50}, {1, 60}};

    cout << FindMaxSolution(tasks) << endl;
    return 0;
}
