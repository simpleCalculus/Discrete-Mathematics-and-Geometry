/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Codec {

    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        if (root == null)
            return "[]";
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        StringBuilder ser = new StringBuilder("[" + root.val + ",");
        while (!q.isEmpty()) {
            TreeNode node = q.poll();
            if (node.left == null)
                ser.append("null,");
            else {
                ser.append(node.left.val + ",");
                q.add(node.left);
            }
            if (node.right == null)
                ser.append("null,");
            else {
                q.add(node.right);
                ser.append(node.right.val + ",");
            }
        }
        return ser.substring(0, ser.length() - 1) + "]";
    }
    
    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        data = data.substring(1, data.length() - 1);
        if (data.equals("")) return null;
        String[] array = data.split(",");
        Queue<TreeNode> q = new LinkedList<>();
        TreeNode tree = new TreeNode(Integer.parseInt(array[0]));
        q.add(tree);
        for (int i = 1; i < array.length; ++i) {
            TreeNode parent = q.poll();
            if (!array[i].equals("null"))
            {
                TreeNode left = new TreeNode(Integer.parseInt(array[i]));
                parent.left = left;
                q.add(left);
            }
            if (!array[++i].equals("null"))
            {
                TreeNode right = new TreeNode(Integer.parseInt(array[i]));
                parent.right = right;
                q.add(right);
            }
        }
        return tree;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec ser = new Codec();
// Codec deser = new Codec();
// TreeNode ans = deser.deserialize(ser.serialize(root));
