/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} val
 * @return {ListNode}
 */
var removeElements = function(head, val) {
    var start = head;
    var prev = start;

    if (!head) return head;

    while (start) {
        if (start.val == val) {
            if (start == head) {
                head = head.next;
                prev = start.next;
                start = start.next;
            } else {
                prev.next = start.next;
                start = start.next;
            }
        } else {
            prev = start;
            start = start.next;
        }
    }
    return head;
};