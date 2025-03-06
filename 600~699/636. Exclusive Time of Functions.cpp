class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> v(n, 0);
        stack<int> s;
        int last_timestamp = 0;
        for (const auto& str : logs) {
            int i = 0;
            int j = 0;
            for (; str[j] != ':'; j++);
            int function = stoi(str.substr(i, j));
            i = j + 1;
            j = i;
            for (; str[j] != ':'; j++);
            bool is_start = str[i] == 's';
            int timestamp = stoi(str.substr(j + 1)) + (is_start ? 0 : 1);
            if (!s.empty()) {
                v[s.top()] += timestamp - last_timestamp;
            }
            if (is_start) {
                s.push(function);
            } else {
                s.pop();
            }
            last_timestamp = timestamp;
        }
        return v;
    }
};
