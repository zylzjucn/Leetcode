class HitCounter {
public:
    /** Initialize your data structure here. */
    HitCounter() {
        
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        int i = timestamp % 300;
        if (time[i] != timestamp) {
            time[i] = timestamp;
            count[i] = 1;
        }
        else
            count[i]++;
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        int res = 0;
        for (int i = 0; i < 300; i++)
            if (time[i] > timestamp - 300)
                res += count[i];
        return res;
    }
private:
    int count[300] = {0};
    int time[300] = {0};
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter obj = new HitCounter();
 * obj.hit(timestamp);
 * int param_2 = obj.getHits(timestamp);
 */
