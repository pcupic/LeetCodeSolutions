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
    private void traverse(TreeNode root, HashSet<Integer> hashSet) {
        if(root == null)
            return;
        traverse(root.left, hashSet);
        hashSet.add(root.val);
        traverse(root.right, hashSet);
    }
    public int findSecondMinimumValue(TreeNode root) {
        HashSet<Integer> hashSet = new HashSet<>();
        traverse(root, hashSet);
        Integer[] numbers = hashSet.toArray(new Integer[hashSet.size()]);
        Arrays.sort(numbers);
        if(numbers.length == 1)
            return -1;
        return numbers[1];
    }
}