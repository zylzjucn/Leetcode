// Online C++ compiler to run C++ program online
#include <iostream>
#include <unordered_map>

using namespace std;

class TrieNode {

public:

    unordered_map<char, TrieNode*> children;
    string tag;
    TrieNode() {}
};

TrieNode* BuildTrieTreeForMap(const unordered_map<string, string>& map) {
    TrieNode* root = new TrieNode();
    for (const auto& p : map) {
        TrieNode* node = root;
        for (const auto& c : p.first) {
            char c_lower = tolower(c);
            if (!node->children.count(tolower(c_lower))) {
                TrieNode* next_node = new TrieNode();
                node->children[c_lower] = next_node;
            }
            node = node->children[c_lower];
        }
        node->tag = p.second;
    }
    return root;
}

string ReviewEditor(const string& review, const unordered_map<string, string>& map) {
    TrieNode* root = BuildTrieTreeForMap(map);
    int i = 0;
    string res;
    while (i < review.length()) {
        int j = i;
        TrieNode* node = root;
        int max_len_found = 0;
        string tag;
        while (j < review.length()) {
            if (!node->children.count(tolower(review[j]))) {
                break;
            }
            node = node->children[tolower(review[j])];
            if (!node->tag.empty()) {
                max_len_found = j - i + 1;
                tag = node->tag;
            }
            j++;
        }
        if (max_len_found > 0) {
            res += "[" + tag + "]" + "{" + review.substr(i, max_len_found) + "}";
            i += max_len_found;
        } else {
            res.append(1, review[i]);
            i++;
        }
    }
    return res;
}

int main() {
    unordered_map<string, string> map;
    map["Airbnb"] = "business";
    map["san Francisco"] = "city";
    string review = "I booked a house on Airbnb for my trip to San Francisco. It was a lovely experience.";
    cout << ReviewEditor(review, map) << endl;
    //"I booked a house on [business]{Airbnb} for my trip to [city]{San Francisco}. It was a lovely experience."
    return 0;
}
