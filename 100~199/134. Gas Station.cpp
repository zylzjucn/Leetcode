class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum = gas[0] - cost[0], smin = sum, index = 0, n = gas.size();
        for (int i = 1; i < n; i++) {
            sum += gas[i] - cost[i];
            if (sum < smin) {
                smin = sum;
                index = i;
            }
        }
        return sum >= 0 ? (index + 1) % n : -1; // sexy solution
    }
};
