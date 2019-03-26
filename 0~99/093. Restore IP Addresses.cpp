class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        for (int a = 1; a <= 3; a++)
            for (int b = 1; b <= 3; b++)
                for (int c = 1; c <= 3; c++)
                    for (int d = 1; d <= 3; d++) {
                        if (a + b + c + d == s.length()) {
                            int ia = stoi(s.substr(0, a));
                            int ib = stoi(s.substr(a, b));
                            int ic = stoi(s.substr(a + b, c));
                            int id = stoi(s.substr(a + b + c, d));
                            if (ia < 256 && ib < 256 && ic < 256 && id < 256) {
                                string str;
                                string sa = to_string(ia);
                                string sb = to_string(ib);
                                string sc = to_string(ic);
                                string sd = to_string(id);
                                str = sa.append(1, '.').append(sb).append(1, '.').append(sc).append(1, '.').append(sd);
                                if (str.length() == s.length() + 3)
                                    res.push_back(str);
                            }
                        }
                    }
        return res;
    }
};
