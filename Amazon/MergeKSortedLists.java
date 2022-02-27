class MergeKSortedLists {
    public ListNode mergeKLists(ListNode[] lists) {
        if (lists.length == 0) return null;
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for (ListNode list : lists) {
            ListNode temp = list;
            while (temp != null) {
                pq.add(temp.val);
                temp = temp.next;
            }
        }
        if (pq.isEmpty()) return null;
        List<Integer> arr = new ArrayList<>();
        ListNode head;
        ListNode node = new ListNode(pq.poll());
        head = node;
        ListNode temp = head;
        while (!pq.isEmpty()) {
            ListNode tempNode = new ListNode(pq.poll());
            temp.next = tempNode;
            temp = temp.next;
        }
        return head;
    }
}
