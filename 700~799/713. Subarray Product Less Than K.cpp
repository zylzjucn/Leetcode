class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int product = 1;
        int res = 0;
        int i = 0;
        for (int j = 0; j < nums.size(); j++) {
            while (i < nums.size() && product * nums[i] < k) {
                product *= nums[i];
                i++;
            }
            if (i > j) {
                res += i - j;
                product /= nums[j];
            } else {
                i++;
            }
            
        }
        return res;
    }
};
