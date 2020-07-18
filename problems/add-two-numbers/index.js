/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function(l1, l2) {
    var carryover = 0;
    var start = null;
    var last = start;
    var l1tmp = l1;
    var l2tmp = l2;

    while (l1tmp != null || l2tmp != null) {
        start = (l1tmp != null) ? l1 : l2;
        last = (l1tmp != null) ? l1tmp : l2tmp;
        var sum = carryover;
        sum = sum + ((l1tmp != null) ? l1tmp.val : 0) + ((l2tmp != null) ? l2tmp.val : 0);
        carryover = (sum >= 10) ? 1 : 0;
        sum = (sum >= 10) ? sum - 10 : sum;
        if (l1tmp != null) l1tmp.val = sum;
        if (l2tmp != null) l2tmp.val = sum;
        l1tmp = (l1tmp != null && l1tmp.next != null) ? l1tmp.next : null;
        l2tmp = (l2tmp != null && l2tmp.next != null) ? l2tmp.next : null;
    }
    if (carryover == 1) {
        last.next = new ListNode(carryover);;
    }

    return start;
};