class SlidingWindowMaximum {
    public int[] maxSlidingWindow(int[] nums, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        Map<Integer, Integer> map = new HashMap<>();
        int n = nums.length;
        for (int i = 0; i < k; ++i) {
            pq.add(nums[i]);
            if (map.containsKey(nums[i])) {
                map.replace(nums[i], map.get(nums[i]) + 1);
            } else {
                map.put(nums[i], 1);
            }
        }
        int[] res = new int[n - k + 1];
        int left = 0;
        int right = k - 1;
        int index = 0;
        while (right < n) {
            while (map.get(pq.peek()) == 0) {
                pq.remove();
            }
            int max = pq.peek();
            map.replace(nums[left], map.get(nums[left]) - 1);
            res[index++] = max;
            left++;
            right++;
            if (right < n) {
                pq.add(nums[right]);
                if (map.containsKey(nums[right])) {
                    map.replace(nums[right], map.get(nums[right]) + 1);
                } else {
                    map.put(nums[right], 1);
                }
            }
        }
        return res;
    }
    public int[] maxSlidingWindowUsingDeque(int[] nums, int k) {
        Deque<Integer> q = new ArrayDeque<>();
        List<Integer> res = new ArrayList<>();
        for (int i = 0; i < nums.length; ++i) {
            while (!q.isEmpty() && nums[q.getLast()] <= nums[i]) {
                q.removeLast();
            }
            q.addLast(i);
            if (q.getFirst() == i - k) {
                q.removeFirst();
            }
            if (i >= k - 1) res.add(nums[q.peek()]);
        }
        int[] output = new int[res.size()];
        int index = 0;
        for (int i : res) {
            output[index++] = i;
        }
        return output;
    }
}
