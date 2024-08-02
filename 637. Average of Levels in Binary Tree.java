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
    public List<Double> averageOfLevels(TreeNode root) {
        List<Double> averages = new LinkedList<>();
        Queue<TreeNode> queue = new LinkedList<>();
        if(root == null) return averages;
        queue.offer(root);
        while(!queue.isEmpty()) {
            int levelSize = queue.size();
            double sum = 0;
            for(int i = 0; i < levelSize; i++) {
                TreeNode current = queue.poll();
                sum += current.val;
                if (current.left != null) queue.offer(current.left);
                if (current.right != null) queue.offer(current.right);
            }
            averages.add(sum / levelSize);
        }
        return averages;
    }
}