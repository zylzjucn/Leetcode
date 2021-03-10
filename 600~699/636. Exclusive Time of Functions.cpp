class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs_string) {
        vector<int> res(n, 0);
        vector<vector<int>> logs = transform(logs_string);
        stack<int> s;
        int time = 0;
        for (const auto log : logs) {
            if (log[1] == 1) {
                if (!s.empty()) {
                    int id = s.top();
                    res[id] += log[2] - time;
                }
                time = log[2];
                s.push(log[0]);
            }
            else {
                int id = s.top();
                res[id] += log[2] - time + 1;
                time = log[2] + 1;
                s.pop();
            }
        }
        return res;
    }
    
    vector<vector<int>> transform(vector<string>& logs) {
        vector<vector<int>> res;
        for (const auto& log : logs) {
            vector<int> v;
            int start = 0;
            int end  = 0;
            while (end < log.length()) {
                if (log[end] != ':')
                    end++;
                else {
                    if (v.empty()) {
                        v.push_back(stoi(log.substr(start, end)));
                    }
                    else {
                        if (log[start] == 's')
                            v.push_back(1);
                        else
                            v.push_back(-1);
                    }
                    start = end + 1;
                    end++;
                }
            }
            v.push_back(stoi(log.substr(start)));
            res.push_back(v);
        }
        return res;
    }
};
