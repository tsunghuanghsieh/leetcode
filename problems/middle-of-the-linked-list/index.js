/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var middleNode = function(head) {
    var fast = head;
    var slow = head;
    var count = 0;
    while (fast != null) {
        fast = fast.next;
        count++;
        if (count % 2 == 0) {
            slow = slow.next;
        }
    }
    return slow;
};