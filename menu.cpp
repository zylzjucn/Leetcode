// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <limits.h>

using namespace std;

struct EntryItem{
    double price;
    int mask;
};

unordered_map<string, int> item_to_index;
vector<EntryItem> entry_items;
vector<int> memo;

int solve(int needed_mask) {
    // Base Case: 如果什么都不需要了，花费为0
    if (needed_mask == 0) {
        return 0;
    }

    // Memoization Check: 如果已经计算过，直接返回结果
    if (memo[needed_mask] != -1) {
        return memo[needed_mask];
    }

    int min_price = INT_MAX;

    // 遍历菜单上的所有选项 (包括单品和套餐)
    for (const auto& item : entry_items) {
        // 如果这个菜单项至少提供了一个我们需要的物品
        if ((needed_mask & item.mask) > 0) {
            // 递归计算购买此项后，凑齐剩余物品的最低花费
            int remaining_cost = solve(needed_mask & (~item.mask));
            
            // 如果子问题有解 (不是无穷大)
            if (remaining_cost != INT_MAX) {
                min_price = min(min_price, (int)item.price + remaining_cost);
            }
        }
    }

    // 存储结果并返回
    return memo[needed_mask] = min_price;
}

double findCheapestSolution(const vector<string>& items, vector<vector<string>>& menu) {
    int index = 0;
    for (const auto& item : items) {
        if (!item_to_index.count(item)) {
            item_to_index[item] = index++;
        }
    }
    unordered_map<int, double> optimized_singles;
    for (const auto& entry : menu) {
        EntryItem entry_item;
        entry_item.price = stod(entry[0]);
        entry_item.mask = 0;
        bool is_dish_found = false;
        for (const auto& dish : entry) {
            if (item_to_index.count(dish)) {
                entry_item.mask |= (1 << item_to_index[dish]);
                is_dish_found = true;
            }
        }
        
        if (is_dish_found) {
            if (entry.size() == 2) {
                if (optimized_singles.count(entry_item.mask)) {
                    optimized_singles[entry_item.mask] = min(optimized_singles[entry_item.mask], entry_item.price);
                } else {
                    optimized_singles[entry_item.mask] = entry_item.price;
                }
            } else {
                entry_items.push_back(entry_item);
            }
        }
    }
    
    for (const auto [mask, price] : optimized_singles) {
        entry_items.push_back({price, mask});
    }
    
    memo.assign(1 << items.size(), -1);
    
    int target_mask = (1 << items.size()) - 1;
    int result = solve(target_mask);

    return result == INT_MAX ? -1 : result;
}


int main() {

vector<vector<string>> menu = {    
    {"5.00", "pizza"},
    {"8.00", "sandwich", "coke"},
    {"4.00", "pasta"},
    {"2.00", "coke"},
    {"6.00", "pasta", "coke", "pizza"},
    {"8.00", "burger", "coke", "pizza"},
    {"5.00", "sandwich"}};

    vector<string> items = {"burger", "pasta"};
    cout << findCheapestSolution(items, menu) << endl;
    return 0;
}
