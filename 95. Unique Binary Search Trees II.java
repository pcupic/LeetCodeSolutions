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
    private List<TreeNode> generateTrees(int start, int end) {
        List<TreeNode> trees = new LinkedList<>();
        if(start > end) {
            trees.add(null);
            return trees;
        }
        for(int i = start; i <= end; i++) {
            List<TreeNode> leftTrees = generateTrees(start, i - 1);
            List<TreeNode> rightTrees = generateTrees(i + 1, end);
            for(TreeNode left : leftTrees) {
                for(TreeNode right : rightTrees) {
                    TreeNode current = new TreeNode(i);
                    current.left = left;
                    current.right = right;
                    trees.add(current);
                }
            }
        }
        return trees;
    }
    public List<TreeNode> generateTrees(int n) {
        if(n == 0)
            return null;
        return generateTrees(1, n);
    }
}