int search(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value) {
            return i;
        }
    }
    return -1; 
}

struct TreeNode* buildTreeHelper(int* preorder, int* inorder, int inStart, int inEnd, int* preIndex) {
    if(inStart > inEnd) return NULL;
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = preorder[*preIndex];
    newNode->left = NULL;
    newNode->right = NULL;
    int inIndex = search(inorder, inStart, inEnd, preorder[*preIndex]);
    (*preIndex)++;
    newNode->left = buildTreeHelper(preorder, inorder, inStart, inIndex - 1, preIndex);
    newNode->right = buildTreeHelper(preorder, inorder, inIndex + 1, inEnd, preIndex);

    return newNode;

}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    int preIndex = 0;
    return buildTreeHelper(preorder, inorder, 0, inorderSize - 1, &preIndex);
}
