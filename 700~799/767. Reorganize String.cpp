class Solution {
public:
    string reorganizeString(string s) {
        string res;
        vector<pair<int, char>> v;
        auto mycmp = [](pair<int, char> a, pair<int, char> b){
            return a.first < b.first || (a.first == b.first && a.second > b.second);
        };
        priority_queue<pair<int, char>, vector<pair<int, char>>, decltype(mycmp)> pq(mycmp);
        for (int i = 0; i < 26; i++)
            v.emplace_back(0, i + 'a');
        for (const auto& c : s)
            v[c - 'a'].first++;
        for (const auto& p : v)
            if (p.first > 0)
                pq.push(p);
        pair<int, char> p1 = pq.top();
        if (p1.first * 2 > s.length() + 1)
            return res;
        while (pq.size() > 1) {
            p1 = pq.top();
            pq.pop();
            pair<int, char> p2 = pq.top();
            pq.pop();
            res.append(1, p1.second).append(1, p2.second);
            p1.first--;
            p2.first--;
            if (p2.first > 0)
                pq.push(p2);
            if (p1.first > 0)
                pq.push(p1);
        }
        if (!pq.empty())
            res.append(1, pq.top().second);
        return res;
    }
};
