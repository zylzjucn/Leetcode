class Solution {
public:
    string addBinary(string a, string b) {
        string s;
        int carry = 0, a1, b1, c;
        stack<int> s1;
        while (!a.empty() || !b.empty() || carry) {
            if (a.empty())
                a1 = 0;
            else {
                a1 = a.back() - 48;
                a.pop_back();
            }
            if (b.empty())
                b1 = 0;
            else {
                b1 = b.back() - 48;
                b.pop_back();
            }
            c = (a1 + b1 + carry) % 2;
            s1.push(c + 48);
            carry = (a1 + b1 + carry) / 2;
        }
        while (!s1.empty())
        {
            s.push_back(s1.top());
            s1.pop();
        }
        return s;
    }
};
