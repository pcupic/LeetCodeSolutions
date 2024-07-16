void swap(struct TreeNode** a, struct TreeNode** b) {
    struct TreeNode* temp = *a;
    *a = *b;
    *b = temp;
}

struct TreeNode* invertTree(struct TreeNode* root) {
    if(!root) return NULL;
    invertTree(root->left);
    invertTree(root->right);
    swap(&root->left, &root->right);
    return root;
}
