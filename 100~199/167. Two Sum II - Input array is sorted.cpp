class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, h = numbers.size() - 1;
        while (numbers[l] + numbers[h] != target)
            numbers[l] + numbers[h] > target ? h-- : l++;
        vector<int> v{l + 1, h + 1};
        return v;
    }
};
