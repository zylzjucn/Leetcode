class Solution {
public:
    bool canConstruct(string r, string m) 
    {
        int a[26] = {0};
        for (int i = 0; i < m.length(); i++)
            a[m[i] - 'a']++;
        for (int i = 0; i < r.length(); i++)
            if (a[r[i] - 'a']-- ==0)
                return false;
        return true;
    }
};
