class MedianFinder {
    PriorityQueue<Integer> lo = new PriorityQueue<>(Collections.reverseOrder());
    PriorityQueue<Integer> hi = new PriorityQueue<>();
    public MedianFinder() {
        
    }
    
    public void addNum(int num) {
        lo.add(num);
        hi.add(lo.poll());
        if (lo.size() < hi.size()) lo.add(hi.poll());
    }
    
    public double findMedian() {
        return lo.size() > hi.size() ? (double) lo.peek() : ((double) lo.peek() + hi.peek()) * 0.5;
    }
}
