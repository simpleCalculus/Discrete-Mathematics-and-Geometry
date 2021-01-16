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
    public int kthSmallest(TreeNode root, int k) {
        if (root == null)
            return 0;
        List<Integer> ans = new ArrayList<Integer>();
        passageTree(root, ans, k);
        return ans.get(k-1);
    }

    public void passageTree(TreeNode node, List<Integer> ans, int k) {
        if (node.left != null) {
            passageTree(node.left, ans, k);
        }

        ans.add(node.val);

        if (ans.size() < k && node.right != null) {
            passageTree(node.right, ans, k);
        }
    }
}
