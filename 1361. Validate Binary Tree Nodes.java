public class Solution {
    public boolean validateBinaryTreeNodes(int n, int[] leftChild, int[] rightChild) {
        int[] parentCount = new int[n];
        int root = -1;

        for (int i = 0; i < leftChild.length; i++) {
            if (leftChild[i] != -1)
                if (parentCount[leftChild[i]]++ == 1)
                    return false;
            if (rightChild[i] != -1)
                if (parentCount[rightChild[i]]++ == 1)
                    return false;
        }

        for (int i = 0; i < leftChild.length; i++) {
            if (parentCount[i] == 0)
                if (root == -1)
                    root = i;
                else
                    return false;
        }

        if (root == -1) {
            return false;
        }

        return dfs(leftChild, rightChild, root) == n;
    }

    private int dfs(int[] left, int[] right, int root) {
        if (root == -1)
            return 0;
        return 1 + dfs(left, right, left[root]) + dfs(left, right, right[root]);
    }
}