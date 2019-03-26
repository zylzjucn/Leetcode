class MovingAverage {
public:
    /** Initialize your data structure here. */
    int len;
    int sum = 0;
    queue<int> q;
    MovingAverage(int size) {
        len = size;
    }
    
    double next(int val) {
        sum += val;
        q.push(val);
        if (q.size() > len) {
            sum -= q.front();
            q.pop();
        }
            
        return (double)sum / q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */
