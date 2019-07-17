/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    Node* prev = NULL;
    Node* next = NULL;
    Node* child = NULL;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
        for (Node* p = head; p; p = p->next) {
            if (p->child) {
                Node* next = p->next;
                p->next = p->child;
                p->child = NULL;
                p->next->prev = p;
                Node* right = p;
                while (right->next)
                    right = right->next;
                if (next) {
                    right->next = next;
                    next->prev = right;
                }
            }
        }
        return head;
    }
};
