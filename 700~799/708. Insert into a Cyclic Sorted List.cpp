/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        Node* node = new Node(insertVal);
        if (!head) {
            node->next = node;
            return node;
        }
        Node* cur = head, *next = cur->next;
        while (next != head) {
            if ((cur->val <= node->val && node->val <= next->val) || (cur->val > next->val && (cur->val <= node->val || node->val <= next->val))) {
                cur->next = node;
                node->next = next;
                return head;
            }
            cur = next;
            next = next->next;
        }
        cur->next = node;
        node->next = next;
        return head;
    }
};
