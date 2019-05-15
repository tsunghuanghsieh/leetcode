class Solution {
    // found a simpler solution
    // https://www.geeksforgeeks.org/iterative-postorder-traversal-using-stack/#comment-4220256372 by sup2647
    private static void postOrder(Node root) {
        Stack<node> st = new Stack<node>();
        Node lastOut = null, currentTop = null;
        while (true) {
            if (root != null) {
                st.push(root);
                root = root.left;
                continue;
            } else if (st.isEmpty()) {
                break;
            } else {
                currentTop = st.peek();
                if (currentTop.right != null && currentTop.right != lastOut) {
                    root = currentTop.right;
                    continue;
                }
                lastOut = st.pop();
                System.out.print(lastOut.data + " ");
            }
        }
    }
}