class Solution {
public:
    bool isValidSerialization(string preorder) {
        int i = 0;
        int count = 1;
        while (i < preorder.length()) {
            int j = i;
            for (; j < preorder.length() && preorder[j] != ','; j++);
            if (preorder[i] != '#') {
                count++;
            } else {
                count--;
            }
            i = j + 1;
            if (i < preorder.length() && count == 0) {
                return false;
            }
        }
        return count == 0;
    }
};
