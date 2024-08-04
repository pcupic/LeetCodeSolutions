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
    List<List<Integer>> paths = new LinkedList<>();
    private void dfs(TreeNode root, int targetSum, List<Integer> path) {
        if(root == null)
            return;

        path.add(root.val);
        targetSum -= root.val;

        if(root.left == null && root.right == null && targetSum == 0)
            paths.add(new LinkedList<>(path));
        else {
            dfs(root.left, targetSum, path);
            dfs(root.right, targetSum, path);
        }
        path.remove(path.size() - 1);
    }
    public List<List<Integer>> pathSum(TreeNode root, int targetSum) {
        if(root == null)
            return paths;
        dfs(root, targetSum, new LinkedList<>());
        return paths;
    }
}