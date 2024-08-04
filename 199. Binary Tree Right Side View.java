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
    List<Integer> rigthSide = new LinkedList<>();
    public List<Integer> rightSideView(TreeNode root) {
        if(root == null)
            return rigthSide;
        Stack<TreeNode> stack = new Stack<>();
        Stack<Integer> level = new Stack<>();
        stack.push(root);
        level.push(0);
        while(!stack.isEmpty()) {
            TreeNode current = stack.pop();
            int depth = level.pop();
            if(depth == rigthSide.size())
                rigthSide.add(current.val);
            if(current.left != null) {
                stack.push(current.left);
                level.push(depth + 1);
            }
            if(current.right != null) {
                stack.push(current.right);
                level.push(depth + 1);
            }
        }
        return rigthSide;
    }
}