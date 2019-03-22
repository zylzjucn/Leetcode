class Solution {
public:
    int evalRPN(vector<string>& v) {
        stack<int> s;
        for(int i=0; i<v.size(); i++) {
            if(v[i]=="+" || v[i]=="-" || v[i]=="*" || v[i]=="/") {
                int a, b;
                b = s.top();
                s.pop();
                a = s.top();
                s.pop();
                char c = v[i][0];
                switch(c) {
                    case '+':
                        s.push(a + b);
                        break;
                    case '-':
                        s.push(a - b);
                        break;
                    case '*':
                        s.push(a * b);
                        break;
                    case '/':
                        s.push(a / b);
                        break;
                    default:
                        break;
                }
            }
            else
                s.push(stoi(v[i]));
        }
        return s.top();
    }
};
