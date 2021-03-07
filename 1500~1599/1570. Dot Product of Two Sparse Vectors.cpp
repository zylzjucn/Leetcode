class SparseVector {
    
public:
    
    vector<pair<int, int>> v;
    
    SparseVector(vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] != 0)
                v.emplace_back(i, nums[i]);
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        vector<pair<int, int>> v1 = vec.v;
        int res = 0;
        int i = 0;
        int j = 0;
        while (i < v.size() && j < v1.size()) {
            if (v[i].first == v1[j].first) {
                res += v[i].second * v1[j].second;
                i++;
                j++;
            }
            else if (v[i].first < v1[j].first)
                i++;
            else
                j++;
        }
        return res;
        
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);
