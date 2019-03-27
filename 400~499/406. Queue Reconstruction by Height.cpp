class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        vector<pair<int, int>> res;
        auto comp = [](pair<int, int> a, pair<int, int> b) {
            return (a.first > b.first || (a.first == b.first && a.second < b.second));
        };
        sort(people.begin(), people.end(), comp);
        for (const auto& p : people)
            res.insert(res.begin() + p.second, p);
        return res;
    }
};
