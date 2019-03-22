class Solution {
public:
    int lengthOfLastWord(string s) 
    {
        while (s.back() == ' ') {
            s.pop_back();
            if(s.length() == 0)
                break;
        }
        int l = 0;
        for (int i = s.size() - 1; i >= 0 && s[i] != ' '; i--)
            l++;
        return l;
    }
};
