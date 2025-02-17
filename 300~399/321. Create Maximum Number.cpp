class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        // calculate the longest possible subarray for each nums
        int len1 = min((int)nums1.size(), k);
        int len2 = min((int)nums2.size(), k);
        vector<vector<int>> subarray1;
        vector<vector<int>> subarray2;
        // subarray1.push_back(findBiggestNumberInSingleArray(nums1, len1));
        // subarray2.push_back(findBiggestNumberInSingleArray(nums2, len2));
        // int i = 0;
        // int j = 0;
        // for (int len = len1 - 1; len >= k - len2; len--) {
        //     subarray1.push_back(deleteOneInSubarray(subarray1.back(), i));
        //     subarray2.push_back(deleteOneInSubarray(subarray2.back(), j));
        // }
        for (int l1 = len1, l2 = len2; l1 >= k - len2; l1--, l2--) {
            subarray1.push_back(findBiggestNumberInSingleArray(nums1, l1));
            subarray2.push_back(findBiggestNumberInSingleArray(nums2, l2));
        }
        vector<int> res;
        for (int l = 0; l < subarray1.size(); l++) {
            vector<int> cur = combineArrays(subarray1[l], subarray2[subarray2.size() - l - 1]);
            if (res.empty() || isSmaller(res, 0, cur, 0)) {
                res = cur;
            }
        }
        return res;
    }

    vector<int> combineArrays(const vector<int>& v1, const vector<int>& v2) {
        vector<int> res;
        int i = 0, j = 0;
        while (i < v1.size() && j < v2.size()) {
            if (isSmaller(v1, i, v2, j)) {
                res.push_back(v2[j++]);
            } else {
                res.push_back(v1[i++]);
            }
        }
        if (i < v1.size()) {
            res.insert(res.end(), v1.begin() + i, v1.end());
        }
        if (j < v2.size()) {
            res.insert(res.end(), v2.begin() + j, v2.end());
        }
        return res;
    }

    bool isSmaller(const vector<int>& v1, int i, const vector<int>& v2, int j) {
        while (i < v1.size() && j < v2.size() && v1[i] == v2[j]) {
            i++;
            j++;
        }
        if (i == v1.size()) {
            return true;
        }
        if (j == v2.size()) {
            return false;
        }
        return v1[i] < v2[j];
    }

    vector<int> findBiggestNumberInSingleArray(const vector<int>& nums, int k) {
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            while (!res.empty() && res.back() < nums[i] && k - res.size() < nums.size() - i) {
                res.pop_back();
            }
            if (res.size() < k) {
                res.push_back(nums[i]);
            }   
        }
        return res;
    }

    vector<int> deleteOneInSubarray(const vector<int>& nums, int& pos) {
        // pos = 0;
        vector<int> res = nums;
        for (; pos < res.size() - 1 && res[pos] >= res[pos + 1]; pos++);
        if (pos == res.size() - 1) {
            res.pop_back();
            pos--;
        } else {
            res.erase(res.begin() + pos);
        }
        return res;
    }
};
