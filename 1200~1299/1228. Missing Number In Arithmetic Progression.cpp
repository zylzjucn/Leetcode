class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int diff0 = arr[1] - arr[0];
        int diff1 = arr[2] - arr[1];
        if (diff0 != diff1) {
            if (diff0 == 2 * diff1)
                return arr[0] + diff1;
            else
                return arr[2] - diff0;   
        }
        for (int i = 0; i < arr.size() - 1; i++) {
            if (arr[i + 1] != arr[i] + diff0)
                return arr[i] + diff0;
        }
        return arr[0];
    }
};
