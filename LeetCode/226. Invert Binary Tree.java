class Solution {
    public TreeNode invertTree(TreeNode root) {
        if (root == null)
            return null;
        TreeNode ans = new TreeNode(root.val);
        helper(ans, root);
        return ans;
    }

    public void helper(TreeNode ans, TreeNode root) {
        if (root.right != null) {
            ans.left = new TreeNode(root.right.val);
            helper(ans.left, root.right);
        }
        if (root.left != null) {
            ans.right = new TreeNode(root.left.val);
            helper(ans.right, root.left);
        }
    }
}
