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
    int maxDiameter = -1;
    private int CalculateDepth(TreeNode root) {
        if(root == null) return 0;
        int leftDepth = CalculateDepth(root.left);
        int rightDepth = CalculateDepth(root.right);
        maxDiameter = Math.max(maxDiameter, leftDepth + rightDepth);
        return Math.max(leftDepth, rightDepth) + 1;
    }
    public int diameterOfBinaryTree(TreeNode root) {
        CalculateDepth(root);
        return maxDiameter;
    }
}