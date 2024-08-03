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
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> zigzag = new LinkedList<>();
        if(root == null)
            return zigzag;
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        boolean isEven = true;
        while(!queue.isEmpty()) {
            int levelSize = queue.size();
            LinkedList<Integer> nodes = new LinkedList<>();
            for(int i = 0; i < levelSize; i++) {
                TreeNode current = queue.poll();
                if(isEven)
                    nodes.addLast(current.val);
                else
                    nodes.addFirst(current.val);
                if(current.left != null)
                    queue.offer(current.left);
                if(current.right != null)
                    queue.offer(current.right);
            }
            zigzag.add(nodes);
            isEven = !isEven;
        }
        return zigzag;
    }
}