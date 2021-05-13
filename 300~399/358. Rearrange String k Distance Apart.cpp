class Solution {
public:
    string rearrangeString(string s, int k) {
        string res;
        vector<int> count(26, 0);
        vector<int> valid_pos(26, 0);
        for (const auto& c : s)
            count[c - 'a']++;
        for (int i = 0; i < s.length(); i++) {
            int candidate = find_valid_candidate(count, valid_pos, i);
            if (candidate == -1)
                return "";
            count[candidate]--;
            valid_pos[candidate] += k;
            res.append(1, 'a' + candidate);
        }
        return res;
    }
    
    int find_valid_candidate(const vector<int>& count, const vector<int>& valid_pos, int index) {
        int c = -1;
        int count_max = INT_MIN;
        for (int i = 0; i < count.size(); i++) {
            if (index >= valid_pos[i] && count[i] > count_max && count[i] > 0) {
                c = i;
                count_max = count[i];
            }
        }
        return c;
    }
};
