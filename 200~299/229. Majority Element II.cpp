class Solution {
public:
    vector<int> majorityElement(vector<int>& n) {
        int flag1 = 99;
        int n1 = 0;
        int flag2 = 88;
        int n2 = 0;
        vector<int> v;
        for (int i = 0; i < n.size(); i++) {
            if (n[i] == flag1)
                n1++;
            else if (n[i] == flag2)
                n2++;
            else {
                if (n1 == 0) {
                    flag1 = n[i];
                    n1 = 1;
                }
                else if (n2 == 0) {
                    flag2 = n[i];
                    n2 = 1;
                }
                else {
                    n1--;
                    n2--;
                }
            }
        }
        n1 = 0;
        n2 = 0;
        for (int i = 0; i < n.size(); i++) {
            if (n[i] == flag1)
                n1++;
            else if (n[i] == flag2)
                n2++;
        }
        if (n1 > n.size() / 3)
            v.push_back(flag1);
        if (n2 > n.size() / 3)
            v.push_back(flag2);
        return v;
    }
};
