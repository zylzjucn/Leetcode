class MyCircularQueue {
    
    vector<int> v;
    int start = 0;
    int next = 0;
    int len = 0;
    int count = 0;
    
public:
    MyCircularQueue(int k) {
        vector<int> v1 = vector<int>(k, 0);
        v = v1;
        len = k;
    }
    
    bool enQueue(int value) {
        if (!isFull()) {
            v[next++] = value;
            if (next == len)
                next = 0;
            count++;
            return true;
        }
        return false;
    }
    
    bool deQueue() {
        if (isEmpty())
            return false;
        start++;
        if (start == len)
            start = 0;
        count--;
        return true;
    }
    
    int Front() {
        if (isEmpty())
            return -1;
        return v[start];
    }
    
    int Rear() {
        if (isEmpty())
            return -1;
        return next != 0 ? v[next - 1] : v.back();
    }
    
    bool isEmpty() {
        return count == 0;
    }
    
    bool isFull() {
        return count == len;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
