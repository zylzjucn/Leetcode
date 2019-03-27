class Solution {
public:
    vector<string> fullJustify(vector<string>& v, int k) {
        vector<string> res;
        if (v.size() == 0) {
            string t(k, ' ');
            res.push_back(t);
        }
        int i = 0;
        while (i < v.size()) {
            int j = i + 1;
            int len = v[i].length();
            while (j < v.size() && len < k) {
                if (k - len >= v[j].length() + 1) {
                    len += v[j].length() + 1;
                    j++;
                }
                else
                    break;
            }
            string t;
            if (j < v.size())
                t = form(v, i, j, k);
            else {
                t = v[i];
                i++;
                for (; i < v.size(); i++)
                    t.append(" ").append(v[i]);
                while (t.length() < k)
                    t.append(" ");
            }
            res.push_back(t);
            i = j;
        }
        return res;
    }
    string form(vector<string>& v, int start, int end, int k) {
        int blank = k;
        string s;
        for (int i = start; i != end; i++)
            blank -= v[i].length();
        int numblank = end - start - 1;
        if (numblank == 0) {
            string bl(k - v[start].length(), ' ');
            s.append(v[start]).append(bl);
            return s;
        }
        int left = blank % numblank;
        int b = blank / numblank;
        string bl(b, ' ');
        s = v[start];
        for (int i = start + 1; i < end; i++) {
            if (left-- > 0)
                s.append(" ");
            s.append(bl).append(v[i]);
        }
        return s;
    }
};
