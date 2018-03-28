class Solution {
public:
    int climbStairs(int n) 
    {
        if(n==1)
            return 1;
        queue<int> q;
        q.push(1);
        q.push(2);
        for(int i=2; i<n; i++)
        {
            q.push(q.front() + q.back());
            q.pop();
        }
        return q.back();
    }
};
