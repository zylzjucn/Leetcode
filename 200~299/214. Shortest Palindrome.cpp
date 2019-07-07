class Solution {
public:
    string shortestPalindrome(string s) {
        
        string t = s;
        reverse(t.begin(), t.end());
        string l = s + "#" + t;
        
        vector<int> v(l.length(), 0);
        for (int i = 1; i < l.length(); i++) {
            int j = v[i - 1];
            while (j > 0 && l[i] != l[j])
                j = v[j - 1];
            v[i] = j += (l[i] == l[j]);
        }
        
        return t.substr(0, s.length() - v.back()) + s;
    }
};
