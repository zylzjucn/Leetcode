class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& w) {
        map<char, string> m;
        map<string, int> res;
        m['a'] = ".-";
        m['b'] = "-...";
        m['c'] = "-.-.";
        m['d'] = "-..";
        m['e'] = ".";
        m['f'] = "..-.";
        m['g'] = "--.";
        m['h'] = "....";
        m['i'] = "..";
        m['j'] = ".---";
        m['k'] = "-.-";
        m['l'] = ".-..";
        m['m'] = "--";
        m['n'] = "-.";
        m['o'] = "---";
        m['p'] = ".--.";
        m['q'] = "--.-";
        m['r'] = ".-.";
        m['s'] = "...";
        m['t'] = "-";
        m['u'] = "..-";
        m['v'] = "...-";
        m['w'] = ".--";
        m['x'] = "-..-";
        m['y'] = "-.--";
        m['z'] = "--..";
        for (int i = 0; i < w.size(); i++) {
            string s;
            for (int j = 0; j < w[i].length(); j++) {
                s = s + m[w[i][j]];
            }
            res[s] = 1;
        }
        return res.size();
    }
};
