/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<int, Node*> m;
        return build(node, m);
    }
    
    Node* build(Node* root, unordered_map<int, Node*>& m) {
        Node* node = new Node(root->val);
        m[node->val] = node;
        for (const auto& p : root->neighbors) {
            if (m.count(p->val))
                node->neighbors.push_back(m[p->val]);
            else
                node->neighbors.push_back(build(p, m));
        }
        return node;
    }
};
