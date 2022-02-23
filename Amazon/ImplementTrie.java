class Trie {
    static class Node {
        private int flag;
        private Node[] children = new Node[26];
    }
    
    private Node root = new Node();

    public Trie() {
        
    }
    
    public void insert(String word) {
        int n = word.length();
        Node temp = root;
        int i = 0;
        while (i < n) {
            int c = word.charAt(i) - 'a';
            if (temp.children[c] == null) {
                temp.children[c] = new Node();
            }
            temp = temp.children[c];
            i++;
        }
        temp.flag = 1;
    }
    
    public boolean search(String word) {
        Node temp = root;
        int n = word.length();
        for (int i = 0; i < n; ++i) {
            int c = word.charAt(i) - 'a';
            if (temp.children[c] == null) return false;
            temp = temp.children[c];
        }
        if (temp.flag == 0) return false;
        return true;
    }
    
    public boolean startsWith(String prefix) {
        Node temp = root;
        int n = prefix.length();
        for (int i = 0; i < n; ++i) {
            int c = prefix.charAt(i) - 'a';
            if (temp.children[c] == null) return false;
            temp = temp.children[c];
        }
        return true;
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * boolean param_2 = obj.search(word);
 * boolean param_3 = obj.startsWith(prefix);
 */
