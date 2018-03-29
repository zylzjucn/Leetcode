class Solution {
public:
    string largestNumber(vector<int>& n) {
        string res;
        vector<string> str;
        for (auto i: n)  //
             str.push_back(to_string(i));
        sort(str.begin(), str.end(), [](string s1, string s2) {return s1 + s2 > s2 + s1;});  // comparison
        for (auto i: str)
            res += i;
        return str[0] == "0" ? "0" : res;  // remove the leading zero
    }  
};
