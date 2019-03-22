class Solution {
public:
    int removeDuplicates(vector<int>& n) {
        if(n.size() == 0)
            return 0;
        if(n.size() == 1)
            return 1;
        int l = 1;
        for (int i =1 ; i < n.size(); i++) {
            if (n[l - 1] != n[i]) {
                n[l] = n[i];
                l++;
            }
        }
        return l;
    }
};
