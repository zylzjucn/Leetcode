/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        vector<int> res;
        int result = 0;
        for (auto l : nestedList)
            DFS(l, 0, res);
        for (int i = res.size() - 1, level = 1; i >= 0; i--, level++) {
            result += res[i] * level;
        }
        return result;
    }
    
    void DFS(NestedInteger& l, int level, vector<int>& res) {
        if (res.size() < level + 1)
            res.push_back(0);
        if (l.isInteger())
            res[level] += l.getInteger();
        else {
            for (auto lnested : l.getList()) {
                DFS(lnested, level + 1, res);
            }
        }
    }
};
