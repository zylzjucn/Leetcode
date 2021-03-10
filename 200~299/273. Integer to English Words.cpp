class Solution {
public:
    string numberToWords(int num) {
        if (num == 0)
            return "Zero";
        string res;
        vector<string> v = {"Thousand", "Million", "Billion"};
        int j = -1;
        string s = to_string(num);
        while (s.length() % 3 != 0)
            s = "0" + s;
        int i = s.length() - 3;
        while (i >= 0) {
            string str = s.substr(i, 3);
            if (j >= 0 && str != "000")
                res = v[j] + " " + res;
            res = numberToWords_3(str) + " " + res;
            j++;
            i -= 3;
        }
        i = 0;
        while (i < res.length() - 1) {
            if (res[i] == ' ' && res[i + 1] == ' ')
                res.erase(i, 1);
            else
                i++;
        }
        while (res.back() == ' ')
            res.pop_back();
        return res;
    }
    
    string numberToWords_3(string s) {
        string res;
        unordered_map<int, string> m1;
        unordered_map<int, string> m2;
        unordered_map<int, string> m3;
        m1[1] = "One";
        m1[2] = "Two";
        m1[3] = "Three";
        m1[4] = "Four";
        m1[5] = "Five";
        m1[6] = "Six";
        m1[7] = "Seven";
        m1[8] = "Eight";
        m1[9] = "Nine";
        m2[2] = "Twenty";
        m2[3] = "Thirty";
        m2[4] = "Forty";
        m2[5] = "Fifty";
        m2[6] = "Sixty";
        m2[7] = "Seventy";
        m2[8] = "Eighty";
        m2[9] = "Ninety";
        m3[10] = "Ten";
        m3[11] = "Eleven";
        m3[12] = "Twelve";
        m3[13] = "Thirteen";
        m3[14] = "Fourteen";
        m3[15] = "Fifteen";
        m3[16] = "Sixteen";
        m3[17] = "Seventeen";
        m3[18] = "Eighteen";
        m3[19] = "Nineteen";
        
        
        if (s[0] != '0')
            res.append(m1[s[0] - '0']).append(" Hundred");
        if (s[1] == '1')
            res.append(" ").append(m3[stoi(s.substr(1))]);
        else if (s[1] == '0')
            res.append(" ").append(m1[s[2] - '0']);
        else {
            res.append(" ").append(m2[s[1] - '0']).append(" ").append(m1[s[2] - '0']);
        }
        return res[0] == ' ' ? res.substr(1) : res;
    }
};
