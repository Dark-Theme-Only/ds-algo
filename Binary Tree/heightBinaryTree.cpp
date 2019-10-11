class TreeNode{
    public:
        int data;
        TreeNode* left;
        TreeNode* right;
};

int height(TreeNode* root){
    if(root == NULL){
        return 0;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    return max(lh,rh) + 1;
}
