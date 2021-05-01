class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        vector<int> res;
        auto cmp = [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        };
        sort(slots1.begin(), slots1.end(), cmp);
        sort(slots2.begin(), slots2.end(), cmp);
        int i = 0;
        int j = 0;
        while (i < slots1.size() && j < slots2.size()) {
            if (slots2[j][1] < slots1[i][0])
                j++;
            else if (slots1[i][1] < slots2[j][0])
                i++;
            else if (slots2[j][1] < slots1[i][1]) {
                if (slots2[j][1] - max(slots1[i][0], slots2[j][0]) >= duration) {
                    res.push_back(max(slots1[i][0], slots2[j][0]));
                    res.push_back(max(slots1[i][0], slots2[j][0]) + duration);
                    break;
                }
                else
                    j++;
            }
            else {
                if (slots1[i][1] - max(slots1[i][0], slots2[j][0]) >= duration) {
                    res.push_back(max(slots1[i][0], slots2[j][0]));
                    res.push_back(max(slots1[i][0], slots2[j][0]) + duration);
                    break;
                }
                else
                    i++;
            }
        }
        return res;
    }
};
