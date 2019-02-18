using System;
namespace addtwonumbers
{
    public class Solution
    {
        public Solution()
        {
        }

        /**
         * Definition for singly-linked list.
         * public class ListNode {
         *     public int val;
         *     public ListNode next;
         *     public ListNode(int x) { val = x; }
         * }
         */
        public ListNode AddTwoNumbers(ListNode l1, ListNode l2)
        {
            int sum = 0;
            int carryover = 0;
            // this will point to the longer of l1 or l2
            ListNode start = new ListNode(0);
            // use reference to reuse l1 and l2
            // so we don't have to create prev and curr in the loop
            ListNode itr1 = l1, itr2 = l2, last = null;
            while (itr1 != null || itr2 != null)
            {
                start.next = (itr1 != null) ? l1 : l2;
                last = (itr1 != null) ? itr1 : itr2;
                sum = carryover;
                if (itr1 != null) sum += itr1.val;
                if (itr2 != null) sum += itr2.val;
                carryover = (sum) / 10;
                sum %= 10;
                if (itr1 != null)
                {
                    itr1.val = sum;
                    itr1 = itr1.next;
                }
                if (itr2 != null)
                {
                    itr2.val = sum;
                    itr2 = itr2.next;
                }
            }

            if (carryover != 0)
            {
                last.next = new ListNode(carryover);
            }
            return start.next;
        }
    }
}
