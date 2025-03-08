class Solution {
public:
    int maximumSwap(int num) {
        string str = to_string(num);
        int small_index = str.length();
        int big_index_found = str.length();
        int big_index = str.length() - 1;

        for (int i = str.length() - 2; i >= 0; i--) {
            if (str[i] < str[big_index]) {
                small_index = i;
                big_index_found = big_index;
            } else if (str[i] > str[big_index]) {
                big_index = i;
            }
        }

        if (big_index_found == str.length()) {
            return num;
        }
        swap(str[small_index], str[big_index_found]);
        return stoi(str);
    }
};
