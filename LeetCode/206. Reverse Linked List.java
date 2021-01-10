class ListNode {
    int val;
    ListNode next;

    ListNode() {
    }

    ListNode(int val) {
        this.val = val;
    }

    ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }
}

class Solution {
    public ListNode reverseList(ListNode head) {
        if (head == null)
            return null;
        ListNode rev = new ListNode();
        while (true) {
            rev.val = head.val;
            if (head.next == null)
                break;
            ListNode x = new ListNode();
            x.next = rev;
            rev = x;
            head = head.next;
        }
        return rev;
    }
}

/* Рекурсивный
class Solution {
    public ListNode reverseList(ListNode head) {
        if (head == null)
            return null;
        return helper(new ListNode(), head);
    }
    
    public ListNode helper(ListNode node, ListNode head) {
        node.val = head.val;
        if (head.next == null)
            return node;
        ListNode x = new ListNode();
        x.next = node;
        return helper(x, head.next);
    }
}
*/
