/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    //
    // Start: Actual code implementation referenced by LeetCode
    //
    ListNode nth, ahead;
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ahead = nth = head;
        int pos = 0;
        while (ahead != null) {
            if (pos > n) nth = nth.next;
            ahead = ahead.next;
            pos++;
        }
        if (head == nth && n == pos) {
            head = head.next;
        } else {
            nth.next = nth.next.next;            
        }
        return head;
    }
    //
    // End: Actual code implementation referenced by LeetCode
    //

    // Helper function to construct ListNode from int array
    public ListNode initListNode(int[] nums) {
        ListNode head = new ListNode(0);
        ListNode tmp = head;
        for (int i = 0; i < nums.length; i++) {
            ListNode newNode = new ListNode(nums[i]);
            tmp.next = newNode;
            tmp = newNode;
        }
        return head.next;
    };

    // Helper function to print the content of ListNode
    public void printListNode(ListNode nodes) {
        System.out.print("[");
        while (nodes != null) {
            System.out.print(nodes.val);
            if (nodes.next != null) System.out.print( ",");
            nodes = nodes.next;
        }
        System.out.println("]");
    }

    public ListNode nodes;

    public static void main(String[] args) {
        int nums[] = {1, 2, 3, 4, 5};
        Solution s = new Solution();
        s.nodes = s.initListNode(nums);

        s.removeNthFromEnd(s.nodes, 1);
        s.printListNode(s.nodes);
    }
}