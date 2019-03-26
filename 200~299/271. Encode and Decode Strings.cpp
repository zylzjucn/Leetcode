class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res = to_string(strs.size()).append(" ");
        for (const auto& s : strs) {
            res.append(to_string(s.length())).append(" ");
        }
        for (const auto& s : strs)
            res.append(s);
        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        vector<int> len;
        int i = 0;
        for (; s[i] != ' '; i++);
        int count = stoi(s.substr(0, i));
        i++;
        int start = i;
        for (; len.size() < count; i++) {
            if (s[i] == ' ') {
                len.push_back(stoi(s.substr(start, i - start)));
                start = i + 1;
            }
        }
        for (int j = 0; j < count; j++) {
            res.push_back(s.substr(i, len[j]));
            i += len[j];
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
