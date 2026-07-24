class MedianFinder {
public:
    priority_queue<int> pq;   // max heap

    priority_queue<int, vector<int>, greater<int>> mpq; // min heap

    int count = 0;

    MedianFinder() {
        
    }

    void balance() {

        while (pq.size() < mpq.size() + 1) {
            int ans = mpq.top();
            mpq.pop();
            pq.push(ans);
        }

        while (pq.size() > mpq.size() + 1) {
            int ans = pq.top();
            pq.pop();
            mpq.push(ans);  // num nahi, ans push hoga
        }
    }

    void medianc(int num) {

        if (mpq.empty()) {
            mpq.push(num);
        }
        else if (num >= mpq.top()) {
            mpq.push(num);
        }
        else {
            pq.push(num);
        }

        balance();
    }

    void addNum(int num) {
        medianc(num);
        count++;
    }

    double findMedian() {

        if (count % 2 == 0) {
            double k = (pq.top() + mpq.top()) / 2.0;
            return k;
        }
        else {
            double k = pq.top();
            return k;
        }
    }
};