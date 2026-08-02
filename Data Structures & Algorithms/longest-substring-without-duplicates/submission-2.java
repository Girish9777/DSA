class Solution {
    public int lengthOfLongestSubstring(String s) {
        HashMap<Character, Integer> mp = new HashMap<>();
        // ERROR: HashMap<Integer, Character> should be HashMap<Character, Integer>

        int head = -1;
        int tail = 0;
        int count = 0;
        int ans = 0;

        while (tail < s.length()) {
            while (head + 1 < s.length() && mp.getOrDefault(s.charAt(head + 1), 0) == 0) {
                // ERROR: s[head+1] -> s.charAt(head+1)
                // ERROR: mp.get(...) may return null, use getOrDefault()

                count++;

                mp.put(s.charAt(head + 1), mp.getOrDefault(s.charAt(head + 1), 0) + 1);
                // ERROR: mp.put(s[head+1])++;
                // HashMap values cannot be incremented like this.

                head++;
            }

            if (count > ans) {
                ans = count;
            }

            if (tail > head) {
                tail++;
                head = tail - 1;
            } else {
                mp.put(s.charAt(tail), mp.get(s.charAt(tail)) - 1);
                // ERROR: s[tail] -> s.charAt(tail)
                // ERROR: mp.put(s[tail])--;
                count--;
                tail++;
            }
        }

        return ans;
    }
}