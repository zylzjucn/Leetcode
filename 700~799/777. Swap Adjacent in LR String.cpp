class Solution {
public:
    bool canTransform(string s1, string s2) {
        if (s1.length() != s2.length())
            return false;
        int count = 0;  // > 0 stands for more 'R' in s1 before while < 0 for more 'L' in s2
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] == 'R') {
                if (count < 0)
                    return false;
                count++;
            }
            else if (s1[i] == 'L') {
                if (s2[i] == 'L' && count == 0)
                    continue;
                if (count >= 0)
                    return false;
                count++;
            }
            if (s2[i] == 'L') {
                if (count > 0)
                    return false;
                count--;
            }
            else if (s2[i] == 'R') {
                if (count <= 0)
                    return false;
                count--;
            }
        }
        return count == 0;
    }
};
