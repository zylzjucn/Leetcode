class Solution {
public:
    string convert(string s, int n) 
    {
        if(n <= 1)
            return s;
        string *sn = new string[n];
        int i = 0, row = 0, step = 1;
        for (; i < s.length(); i++) {
            sn[row].push_back(s[i]);
            if (row == 0)
                step = 1;
            else if (row == n-1)
                step = -1;
            row += step;
        }
        s.clear();
        for (i = 0; i < n; i++)
            s.append(sn[i]);
        return s;
    }
};
