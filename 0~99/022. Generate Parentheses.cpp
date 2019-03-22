class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        goDown (res, "", n, 0);
        return res;
    }
    void goDown(vector<string> &res, string s, int n, int more) {
        if (more == 0 && n == 0) {
            res.push_back(s);
            return;
        }
        if (n > 0)
            goDown(res, s + "(", n - 1, more + 1);
        if (more > 0)
            goDown(res, s + ")", n, more - 1);
        //s.pop_back();
    }
};
