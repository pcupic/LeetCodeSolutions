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
    private void dfs(TreeNode root, StringBuilder path, List<String> allPaths) {
        if(root == null)
            return;
        int length = path.length();
        path.append(root.val);
        if(root.right == null && root.left == null)
            allPaths.add(path.toString());
        else {
            path.append("->");
            dfs(root.left, path, allPaths);
            dfs(root.right, path, allPaths);
        }
        path.setLength(length);
    }
    public List<String> binaryTreePaths(TreeNode root) {
        List<String> allPaths = new LinkedList<>();
        dfs(root, new StringBuilder(), allPaths);
        return allPaths;
    }
}