class NumArray {
public:
    NumArray(vector<int> nums) {
        for (const auto n : nums)
            v.push_back(v.back() + n);
    }
    
    int sumRange(int i, int j) {
        return v[j + 1] - v[i];
    }
    
private:
    vector<int> v = {0};
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
