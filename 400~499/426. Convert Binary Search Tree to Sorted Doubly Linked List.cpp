/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (!root)
            return root;
        Node* l = root->left;
        Node* r = root->right;
        root->left = root;
        root->right = root;
        Node* node = l ? merge(treeToDoublyList(l), root) : root;
        node = r ? merge(node, treeToDoublyList(r)) : node;
        return node;
    }

private:
    Node* merge(Node* node1, Node* node2) {
        node1->left->right = node2;
        node2->left->right = node1;
        Node* tmp = node2->left;
        node2->left = node1->left;
        node1->left = tmp;
        return node1;
    }
};
