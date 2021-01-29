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
   
   public List<List<Integer>> levelOrder(TreeNode root) {
        Queue<List<TreeNode>> queue = new LinkedList<>();
        List<TreeNode> ls = new LinkedList<>();
        ls.add(root);
        queue.add(ls);
        List<List<Integer>> ans = new LinkedList<>();
        if (root == null)
            return ans;
        while (!queue.isEmpty()) {
            List<TreeNode> nodesChildren = new LinkedList<>();
            List<TreeNode> nodes = queue.poll();
            List<Integer> nodeValues = new LinkedList<>();
            for(TreeNode node : nodes) {
                nodeValues.add(node.val);
                if (node.left != null)
                    nodesChildren.add(node.left);
                if (node.right != null)
                    nodesChildren.add(node.right);
            }
            ans.add(new LinkedList<>(nodeValues));
            if (nodesChildren.size() > 0)
                queue.add(new LinkedList<>(nodesChildren));
        }
        return ans;
    }
