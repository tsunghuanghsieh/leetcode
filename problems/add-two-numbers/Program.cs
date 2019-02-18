using System;
using System.IO;

namespace addtwonumbers
{
    class MainClass
    {
        static Solution soln = new Solution();

        public static void Main(string[] args)
        {
            int[] line1 = { };
            int[] line2 = { };
            foreach (string file in Directory.EnumerateFiles("../../test cases", "test??.txt"))
            {
                string[] lines = File.ReadAllLines(file);
                string answer = File.ReadAllText(file.Insert(file.IndexOf(".txt", StringComparison.CurrentCultureIgnoreCase), "r"));

                //Console.WriteLine(lines[0]);
                //Console.WriteLine(lines[1]);

                line1 = Array.ConvertAll(lines[0].Trim(new char[] { '[', ']' }).Split(','), s => int.Parse(s));
                line2 = Array.ConvertAll(lines[1].Trim(new char[] { '[', ']' }).Split(','), s => int.Parse(s));

                ListNode result = soln.AddTwoNumbers(createListNode(line1), createListNode(line2));
                Console.WriteLine(answer);
                printListNode(result);
                Console.WriteLine("");
            }
        }

        // Create ListNode from int array
        public static ListNode createListNode(int[] numbers)
        {
            ListNode start = new ListNode(0);
            ListNode curr = start;

            foreach (int number in numbers)
            {
                curr.next = new ListNode(number);
                curr = curr.next;
            }
            return start.next;
        }

        // Format and print number in ListNode
        public static void printListNode(ListNode result)
        {
            ListNode itr = result;
             
            Console.Write('[');
            while (itr != null)
            {
                Console.Write(itr.val);
                if (itr.next != null) Console.Write(',');
                itr = itr.next;
            }
            Console.Write("]\n");
        }
    }
}
