class Solution {
public:
    string validIPAddress(string s) {
        if (valid_IPv4(s))
            return "IPv4";
        if (valid_IPv6(s))
            return "IPv6";
        return "Neither";
    }
    
    bool valid_IPv4(string s) {
        int start = 0;
        int end = 0;
        int count = 0;
        while (end < s.length()) {
            while (end < s.length() && s[end] != '.') {
                if (!isdigit(s[end]))
                    return false;
                if (end - start > 3)
                    return false;
                end++;
            }
            if (start == end)
                return false;
            int val = stoi(s.substr(start, end - start));
            if (s.substr(start, end - start) != to_string(val) || val > 255 || val < 0)
                return false;
            count++;
            if (count == 4)
                break;
            end++;
            start = end;
        }
        return count == 4 && end == s.length();
    }
    
    bool valid_IPv6(string s) {
        int start = 0;
        int end = 0;
        int count = 0;
        while (end < s.length()) {
            while (end < s.length() && s[end] != ':')
                end++;
            if (end - start < 1 || end - start > 4)
                return false;
            while (start != end) {
                if (isdigit(s[start]) || (s[start] >= 'a' && s[start] <= 'f') || (s[start] >= 'A' && s[start] <= 'F'))
                    start++;
                else
                    return false;
            }
            count++;
            if (count == 8)
                break;
            end++;
            start = end;
        }
        return count == 8 && end == s.length();
    }
};
