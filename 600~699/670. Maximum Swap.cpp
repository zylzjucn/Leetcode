class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int maxindex = s.length() - 1;
        int minindex = s.length() - 1;
        for (int i = s.length() - 2; i >= 0; i--) {
            if (s[i] < s[maxindex])
                minindex = i;
            else if (s[i] > s[maxindex])
                maxindex = i;
        }
        if (minindex >= maxindex) {
            maxindex = minindex;
            for (int i = minindex + 1; i < s.length(); i++) {
                if (s[i] >= s[maxindex])
                    maxindex = i;
            }
        }
        swap(s[minindex], s[maxindex]);
        return stoi(s);
    }
};
