/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if (l1 == null) {
            return l2;
        } else if (l2 == null) {
            return l1;
        }
        ListNode list_begin = new ListNode();
        ListNode node = list_begin;
        while(l1 != null || l2 != null) {
            if (l1 == null) {
                node.next = l2;
                break;
            } else if (l2 == null) {
                node.next = l1;
                break;
            }
            if (l1.val <= l2.val) {
                node.val = l1.val;
                l1 = l1.next;
            } else if (l2.val < l1.val) {
                node.val = l2.val;
                l2 = l2.next;
            }
            if (l1 != null && l2 != null) {
                node.next = new ListNode();
                node = node.next;
            }
        }
        return list_begin;
    }
}
