class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        int time = 0;

        vector<int> arr(26, 0);

        // Frequency count
        for (int i = 0; i < tasks.size(); i++) {
            arr[tasks[i] - 'A']++;
        }

        // Frequencies heap me push karo
        for (int i = 0; i < 26; i++) {
            if (arr[i] > 0) {
                pq.push(arr[i]);
            }
        }

        while (!pq.empty()) {
            vector<int> temp;

            for (int i = 1; i <= n + 1; i++) {
                if (!pq.empty()) {
                    int freq = pq.top();
                    pq.pop();      // tumhare code me missing tha

                    freq--;
                    temp.push_back(freq);
                }
            }

            for (int &g : temp) {
                if (g > 0) {
                    pq.push(g);
                }
            }

            if (pq.empty()) {
                time += temp.size();
            } else {
                time += n + 1;
            }
        }

        return time;
    }
};