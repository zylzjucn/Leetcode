// Online C++ compiler to run C++ program online
#include <iostream>
#include <unordered_map>
#include <climits>
#include <vector>

using namespace std;

int solve(const int& items_needed, const unordered_map<int, int>& menu_item_bit_to_price, unordered_map<int, int>& memo) {
    if (items_needed == 0) {
        return 0;
    }
    if (memo.count(items_needed)) {
        return memo[items_needed];
    }
    int min_price = INT_MAX;
    for (auto [items_bit, price] : menu_item_bit_to_price) {
        if ((items_bit & items_needed) == 0) {
            continue;
        } else {
            int rest_price = solve(items_needed & (~items_bit), menu_item_bit_to_price, memo);
            if (rest_price < INT_MAX) {
                min_price = min(min_price, price + rest_price);
            }
        }
    }
    return memo[items_needed] = min_price;
}

int findCheapestSolution(const vector<string>& items, const vector<vector<string>>& menu) {
    unordered_map<string, int> item_to_bit;
    int index = 0;
    for (const auto& item : items) {
        if (!item_to_bit.count(item)) {
            item_to_bit[item] = index++;
        }
    }
    unordered_map<int, int> menu_item_bit_to_price;
    for (const auto& menu_items : menu) {
        int price = stoi(menu_items[0]);
        int cur_bit = 0;
        for (const auto& item : menu_items) {
            if (item_to_bit.count(item)) {
                cur_bit |= (1 << item_to_bit[item]);
            }
        }
        if (!menu_item_bit_to_price.count(cur_bit) || menu_item_bit_to_price[cur_bit] > price) {
            menu_item_bit_to_price[cur_bit] = price;
        }
    }
    int items_needed = (1 << index) - 1;
    unordered_map<int, int> memo;
    return solve(items_needed, menu_item_bit_to_price, memo);
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
