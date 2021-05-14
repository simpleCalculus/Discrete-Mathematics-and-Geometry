/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public boolean hasCycle(ListNode head) {
        int max_nodes = 10000;
        while(head != null && max_nodes > 0) {
            max_nodes--;
            head = head.next;
        }
        return (head != null);
    }
}
