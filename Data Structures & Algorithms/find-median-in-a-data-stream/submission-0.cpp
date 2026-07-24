class MedianFinder {
public:
    // Smaller half ka maximum element top par rahega
    priority_queue<int> pq;

    // Larger half ka minimum element top par rahega
    priority_queue<int, vector<int>, greater<int>> mpq;

    int count = 0;

    MedianFinder() {
        
    }

    void balance() {
        // Agar min heap badi ho gayi,
        // toh uska smallest element max heap mein bhej do
        if (mpq.size() > pq.size()) {
            int ans = mpq.top();
            mpq.pop();
            pq.push(ans);
        }

        // Max heap mein maximum ek extra element allowed hai
        if (pq.size() > mpq.size() + 1) {
            int ans = pq.top();
            pq.pop();
            mpq.push(ans);
        }
    }

    void medianc(int num) {
        // Pehla element ya smaller element max heap mein jayega
        if (pq.empty() || num <= pq.top()) {
            pq.push(num);
        }
        else {
            mpq.push(num);
        }

        balance();
    }

    void addNum(int num) {
        medianc(num);
        count++;
    }

    double findMedian() {
        // Even number of elements
        if (count % 2 == 0) {
            return ((double)pq.top() + (double)mpq.top()) / 2.0;
        }

        // Odd number of elements
        return pq.top();
    }
};