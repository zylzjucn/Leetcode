class Solution {
public:
    string getHint(string s, string t) {
        int a = 0;
        int b = 0;
        for (int i = 0; i < s.length(); i++)
            if (s[i] == t[i])
                a++;
        unordered_map<char, int> ms;
        unordered_map<char, int> mt;
        for (const auto& cs : s)
            ms[cs]++;
        for (const auto& ct : t)
            mt[ct]++;
        for (auto it = ms.begin(); it != ms.end(); it++)
            if (mt.count(it->first))
                b += min(it->second, mt[it->first]);
        return to_string(a) + "A" + to_string(b - a) + "B";
    }
};
