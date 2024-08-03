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
    public void flatten(TreeNode root) {
        Stack<TreeNode> nodes = new Stack<>();
        if(root == null)
            return;
        nodes.push(root);
        while(!nodes.isEmpty()) {
            TreeNode current = nodes.pop();
            if(current.right != null)
                nodes.push(current.right);
            if(current.left != null)
                nodes.push(current.left);
            if(!nodes.isEmpty())
                current.right = nodes.peek();
            current.left = null;
        }
    }
}