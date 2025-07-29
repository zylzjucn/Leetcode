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

TrieNode* BuildTrieTreeFromMap(const unordered_map<string, string>& map) {
    TrieNode* root = new TrieNode();
    for (const auto& p : map) {
        auto [word, tag] = p;
        TrieNode* node = root;
        for (const auto& c : word) {
            if (!node->children.count(tolower(c))) {
                TrieNode* next_node = new TrieNode();
                node->children[tolower(c)] = next_node;
            }
            node = node->children[tolower(c)];
        }
        node->tag = tag;
    }
    return root;
}

string ReviewEditor(const string& review, const unordered_map<string, string>& map) {
    TrieNode* root = BuildTrieTreeFromMap(map);
    string res;
    int i = 0;
    while (i < review.length()) {
        int j = i;
        int k = -1;
        string tag;
        TrieNode* node = root;
        while (j < review.length() && node->children.count(tolower(review[j]))) {
            node = node->children[tolower(review[j++])];
            if (!node->tag.empty()) {
                k = j;
                tag = node->tag;
            }
        }
        if (k == -1) {
            res.append(1, review[i++]);
        } else {
            res += "[" + tag + "]" + "{" + review.substr(i, k - i) + "}";
            i = k;
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
