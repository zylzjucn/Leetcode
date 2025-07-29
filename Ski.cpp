// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <climits>

using namespace std;

vector<string> findBestRoute(const vector<vector<string>>& travel, const vector<vector<string>>& points) {
    unordered_map<string, unordered_map<string, int>> costs;
    for (const auto& route : travel) {
        costs[route[0]][route[1]] = stoi(route[2]);
    }
    unordered_map<string, int> reward;
    unordered_map<string, int> cost_table;
    for (const auto point : points) {
        reward[point[0]] = stoi(point[1]);
    }
    unordered_map<string, string> parents;
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;
    pq.push({0, "start"});
    while (!pq.empty()) {
        auto [cost, cur_stop] = pq.top();
        pq.pop();
        if (cost_table.count(cur_stop) && cost_table[cur_stop] < cost) {
            continue;
        }
        for (const auto& p : costs[cur_stop]) {
            auto [next_stop, dcost] = p;
            int new_cost = cost + dcost;
            if (!cost_table.count(next_stop) || cost_table[next_stop] > new_cost) {
                cost_table[next_stop] = new_cost;
                parents[next_stop] = cur_stop;
                pq.push({new_cost, next_stop});
            }
        }
    }
    int max_gain = INT_MIN;
    string max_stop = "start";
    
    for (auto& p : reward) {
        auto [stop, gain] = p;
        gain -= cost_table[stop];
        if (gain > max_gain) {
            max_gain = gain;
            max_stop = stop;
        }
    }
    vector<string> res;
    while (max_stop != "") {
        res.push_back(max_stop);
        max_stop = parents[max_stop];
    }
    return res;
}


int main() {
    vector<vector<string>> travel = {
        {"start", "A", "3"},
        {"A", "B", "5"},
        {"B", "C", "5"},
        {"B", "END1", "1"}
    };

    vector<vector<string>> points = {
        {"A", "5"},
        {"B", "6"},
        {"END1", "3"}
    };
    
    for (const auto& str : findBestRoute(travel, points)) {
        cout << str << " ";
    }
    cout << endl;

    return 0;
}
