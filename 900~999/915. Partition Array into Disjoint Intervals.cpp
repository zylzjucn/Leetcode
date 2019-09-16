class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
        int index = 0;
        int maxleft = 0;
        int maxever = 0;
        for (int i = 1; i < A.size(); i++) {
            if (A[i] > A[maxever])
                maxever = i;
            else if (A[i] < A[maxleft]) {
                maxleft = maxever;
                index = i;
            }       
        }
        return index + 1;
    }
};

