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
    int MAX;
    public int diameterOfBinaryTree(TreeNode root) {
        helper(root);
        return MAX;
    }
    
    public int helper(TreeNode root) {
        if (root == null) {
            return 0;
        }   
        int right = 0;
        int left = 0;
        if (root.right != null) {
            right = 1 + helper(root.right);
        }
        if (root.left != null) {
            left = 1 + helper(root.left);
        }
        MAX = Math.max(MAX, left + right);
        // System.out.println(root.val + "   " + MAX);
        return Math.max(left, right);
    }
}
