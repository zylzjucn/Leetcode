class Solution {
public:
    bool rotateString(string A, string B) {
        if (A.length() == 0 && B.length() == 0)
            return true;
        for (int start = 0; start < A.length(); ++start)
            if (A.substr(start, A.length() - start) + A.substr(0, start) == B)
                return true;
        return false;
    }
};
