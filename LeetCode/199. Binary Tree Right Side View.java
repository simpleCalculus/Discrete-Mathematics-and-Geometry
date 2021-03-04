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
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> ls = new LinkedList<>();
        if (root == null)
            return ls;
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        int k = 1;
        while (!q.isEmpty()) {
            int num = 0;
            int cnt = 0;
            for (int i = 0; i < k; ++i) {
                TreeNode t_root = q.poll();
                num = t_root.val;
                if (t_root.left != null) {
                    q.add(t_root.left);
                    cnt++;
                }
                if (t_root.right != null) {
                    q.add(t_root.right);
                    cnt++;
                }
            }
            ls.add(num);
            k = cnt;
        }
        return ls;
    }
}
