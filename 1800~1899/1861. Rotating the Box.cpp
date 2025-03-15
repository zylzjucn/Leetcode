class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        vector res(boxGrid[0].size(), vector<char>(boxGrid.size(), '.'));
        for (int i = 0; i < boxGrid.size(); i++) {
            // the position to fall to
            int pos = boxGrid[0].size() - 1;
            for (int j = boxGrid[0].size() - 1; j >= 0; j--) {
                if (boxGrid[i][j] == '#') {
                    res[pos][boxGrid.size() - i - 1] = '#';
                    pos--;
                } else if (boxGrid[i][j] == '*') {
                    pos = j - 1;
                    res[j][boxGrid.size() - i - 1] = '*';
                }
            }
        }
        return res;
    }
};
