/**
 * This is the interface for the expression tree Node.
 * You should not remove it, and you can define some classes to implement it.
 */

abstract class Node {
    protected Node left;
    protected Node right;
    public abstract int evaluate();
};

class OperatorNode extends Node {
    private char operator;
    
    public OperatorNode(char operator) {
        this.operator = operator;
        super.left = null;
        super.right = null;
    }
    
    @Override
    public int evaluate() {
        if (this.operator == '+') {
            return super.left.evaluate() + super.right.evaluate();
        } else if (this.operator == '-') {
            return super.left.evaluate() - super.right.evaluate();
        } else if (this.operator == '*') {
            return super.left.evaluate() * super.right.evaluate();
        } else {
            return super.left.evaluate() / super.right.evaluate();
        }
    }
}

class OperandNode extends Node {
    private int operand;
    
    public OperandNode(int operand) {
        this.operand = operand;
        super.left = null;
        super.right = null;
    }
    
    @Override
    public int evaluate() {
        return this.operand;
    }
}




/**
 * This is the TreeBuilder class.
 * You can treat it as the driver code that takes the postinfix input 
 * and returns the expression tree represnting it as a Node.
 */

class TreeBuilder {
    Node buildTree(String[] postfix) {
        int n = postfix.length;
        Stack<Node> stack = new Stack<>();
        for (String s : postfix) {
            if (s.equals("+") || s.equals("-") || s.equals("*") || s.equals("/")) {
                Node rightNode = stack.pop();
                Node leftNode = stack.pop();
                Node root = new OperatorNode(s.charAt(0));
                root.left = leftNode;
                root.right = rightNode;
                stack.push(root);
            } else {
                Node node = new OperandNode(Integer.parseInt(s));
                stack.push(node);
            }
        }
        Node result = stack.pop();
        return result;
    }
};


/**
 * Your TreeBuilder object will be instantiated and called as such:
 * TreeBuilder obj = new TreeBuilder();
 * Node expTree = obj.buildTree(postfix);
 * int ans = expTree.evaluate();
 */
