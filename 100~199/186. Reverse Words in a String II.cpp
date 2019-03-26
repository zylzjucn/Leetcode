class Solution {
public:
    void reverseWords(vector<char>& v) {
        for (int i = 0, j = v.size() - 1; i < j; i++, j--)
            swap(v[i], v[j]);
        int l = 0;
        int r;
        for (int i = 0; i < v.size(); i++) {
            if (v[i] == ' ') {
                r = i - 1;
                while (l < r)
                    swap(v[l++], v[r--]);
                l = i + 1;
            }
        }
        r = v.size() - 1;
        while (l < r)
            swap(v[l++], v[r--]);
        return;
    }
};
