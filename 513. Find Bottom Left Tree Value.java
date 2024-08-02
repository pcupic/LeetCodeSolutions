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
    private int maxDepth = -1;
    private int bottomLeftValue;

    public int findBottomLeftValue(TreeNode root) {
        findBottomLeftValue(root, 0);
        return bottomLeftValue;
    }

    private void findBottomLeftValue(TreeNode node, int depth) {
        if (node == null) return;

        if (depth > maxDepth) {
            maxDepth = depth;
            bottomLeftValue = node.val;
        }

        findBottomLeftValue(node.left, depth + 1);
        findBottomLeftValue(node.right, depth + 1);
    }
}