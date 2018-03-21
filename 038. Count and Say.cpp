class Solution {
public:
    string countAndSay(int n) {
        string cur, pre = "1";
        int i, j;
        for (i = 0; i < n - 1; i++) { // care about the situation here to let it into the loop while 0
            cur.clear();
            int start = 0;
            for (j = 1; j < pre.length(); j++) {
                if(pre[j] != pre[j - 1]) {
                    cur.append(to_string(j - start));
                    cur.push_back(pre[j - 1]);
                    start = j;
                }
            }
            cur.append(to_string(j - start));
            cur.push_back(pre[j - 1]);
            pre = cur;  // return pre to roll-back
        }
        return pre;
    }
};
