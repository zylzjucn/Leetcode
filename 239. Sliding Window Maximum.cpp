class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& n, int k) {
        deque<int> dq;  // deque to construct a monotonic queue
        vector<int> v;
        for (int i = 0; i < n.size(); i++) {
            if (!dq.empty() && dq.front() == i - k)
                dq.pop_front();  // use index instead of value to pop_front
            while (!dq.empty() && n[i] >= n[dq.back()])  // the back is no longer needed, maybe several
                dq.pop_back();
            dq.push_back(i);
            if (i >= k-1)
                v.push_back(n[dq.front()]);
        }
        return v;
    }
};
