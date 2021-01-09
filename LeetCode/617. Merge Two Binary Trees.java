/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public TreeNode mergeTrees(TreeNode t1, TreeNode t2) {
        if (t1 == null && t2 == null)
            return null;
        TreeNode t = new TreeNode();
        helper(t, t1, t2);
        return t;
    }

    private void helper(TreeNode t, TreeNode t1, TreeNode t2) {
        if (t1 == null) {
            helper2(t, t2);
        } else if (t2 == null) {
            helper2(t, t1);
        } else {
            t.val = t1.val + t2.val;
            if (t1.right != null || t2.right != null) {
                t.right = new TreeNode();
                helper(t.right, t1.right, t2.right);
            }
            if (t1.left != null || t2.left != null) {
                t.left = new TreeNode();
                helper(t.left, t1.left, t2.left);
            }
        }
    }

    private void helper2(TreeNode t, TreeNode t2) {
        t.val = t2.val;
        if (t2.right != null) {
            t.right = new TreeNode();
            helper2(t.right, t2.right);
        }
        if (t2.left != null) {
            t.left = new TreeNode();
            helper2(t.left, t2.left);
        }
    }
}
