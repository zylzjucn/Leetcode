class Solution {
public:
    bool canPermutePalindrome(string s) {
        set<char> set;
        for (const char& c : s)
            if (set.find(c) != set.end())
                set.erase(c);
            else
                set.insert(c);
        return set.size() <= 1;
    }
};
