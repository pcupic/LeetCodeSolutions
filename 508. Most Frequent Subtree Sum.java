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
    public int[] findFrequentTreeSum(TreeNode root) {
        HashMap<Integer, Integer> freq = new HashMap<>();
        dfs(root, freq);
        int maxFreq = Collections.max(freq.values());
        return freq.entrySet().stream().filter(entry -> entry.getValue() == maxFreq)
                .mapToInt(Map.Entry::getKey).toArray();
    }

    private int dfs(TreeNode root, HashMap<Integer, Integer> freq) {
        if(root == null) return 0;
        int subtreeSum = dfs(root.left, freq) + dfs(root.right, freq) + root.val;
        freq.put(subtreeSum, freq.getOrDefault(subtreeSum, 0) + 1);
        return subtreeSum;
    }
}