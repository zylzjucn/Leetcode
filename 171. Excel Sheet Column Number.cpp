class Solution {
public:
    int titleToNumber(string s) 
    {
        int sum = 0, i = 0;
        for(; i < s.length(); i++)
            sum = 26 * sum + s[i] - 64;
        return sum;
    }
};
